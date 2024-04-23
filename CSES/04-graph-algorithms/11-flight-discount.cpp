#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e16;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int n, int source) {

    vector<int> dist(n+1, inf);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while(!pq.empty()) {

        auto [d, v] = pq.top();
        pq.pop();

        if(d > dist[v]) continue;

        for(auto [x, w]: adj[v]) {
            if(dist[x] > dist[v] + w) {
                dist[x] = dist[v] + w;
                pq.push({dist[x], x});
            }
        }
    }

    return dist;
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>()), adjR(n+1, vector<pair<int, int>>());
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adjR[b].push_back({a, c});
    }

    vector<int> dist_1 = dijkstra(adj, n, 1);
    vector<int> dist_n = dijkstra(adjR, n, n);

    int ans = inf;
    for(int i=1; i<=n; i++) {
        for(auto [j, w]: adj[i]) {
            ans = min(ans, dist_1[i] + w/2 + dist_n[j]);
        }
    }

    cout << ans << "\n";
    return 0;
}