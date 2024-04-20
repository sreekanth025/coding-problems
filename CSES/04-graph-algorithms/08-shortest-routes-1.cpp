#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<int> dist(n+1, inf);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if(d > dist[v]) continue;
        for(auto [x, w]: adj[v]) {
            if(w + d < dist[x]) {
                dist[x] = w + d;
                pq.push({dist[x], x});
            }   
        }
    }

    for(int i=1; i<=n; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}