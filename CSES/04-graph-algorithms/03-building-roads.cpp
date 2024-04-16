#include<bits/stdc++.h>
using namespace std;
#define int long long

void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[v] = true;
    for(int &x: adj[v]) {
        if(!vis[x]) {
            dfs(x, adj, vis);
        }
    }
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>());
    int a, b;
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> heads;
    vector<bool> vis(n+1, false);

    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            heads.push_back(i);
            dfs(i, adj, vis);
        }
    }

    cout << heads.size()-1 << "\n";
    for(int i=1; i<heads.size(); i++) {
        cout << heads[i] << " " << heads[i-1] << "\n";
    }

    return 0;
}