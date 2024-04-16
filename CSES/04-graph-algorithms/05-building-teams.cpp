#include<bits/stdc++.h>
using namespace std;
#define int long long

bool bfs(int v, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& color) {

    vis[v] = true;
    queue<pair<int, int>> q;
    q.push({v, 0});
    color[v] = 0;

    while(!q.empty()) {
        auto [top, c] = q.front();
        q.pop();

        for(int &x: adj[top]) {
            if(!vis[x]) {
                color[x] = 1-c;
                vis[x] = true;
                q.push({x, 1-c});
            }
            else if(color[x] == c) return false;
        }
    }

    return true;
}

bool is_colourable(vector<vector<int>>& adj, int n, vector<int>& color) {
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            bool res = bfs(i, adj, vis, color);
            if(!res) return false;
        }
    }
    return true;
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>());
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n+1, -2);
    bool result = is_colourable(adj, n, color);

    if(result) {
        for(int i=1; i<=n; i++) {
            cout << 1 + color[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}