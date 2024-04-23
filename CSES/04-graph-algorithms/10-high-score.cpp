#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e16;

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    vector<vector<int>> adjR(n+1, vector<int>());

    for(int i=0; i<m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        edges.push_back({a, b, -x});
        adjR[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    queue<int> q;
    q.push(n);
    vis[n] = true;

    // BFS on inverse graph to check if node n is reachable from any given node x.
    while(!q.empty()) {
        auto top = q.front();
        q.pop();

        for(int &x: adjR[top]) {
            if(!vis[x]) {
                vis[x] = true;
                q.push(x);
            }
        }
    }
    

    vector<int> dist(n+1, inf);
    dist[1] = 0;

    // Bellman ford
    for(int i=0; i<n-1; i++) {
        for(auto [a, b, w]: edges) {
            if(dist[a] != inf && (dist[b] > dist[a] + w)) {
                dist[b] = dist[a] + w;
            }
            
        }
    }

    // check for any negative cycle that is on the way from 1 to n
    bool neg_cycle = false;
    for(auto [a, b, w]: edges) {
        if(vis[b] && (dist[a] != inf) && (dist[b] > dist[a] + w)) {
            neg_cycle = true;
            break;
        }
    }

    if(neg_cycle) {
        cout << -1 << "\n";
    }
    else {
        cout << -dist[n] << "\n";
    }

    return 0;
}