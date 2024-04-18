#include<bits/stdc++.h>
using namespace std;
#define int long long

int cycle_start, cycle_end;

bool dfs(int v, int p, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& par) {

    vis[v] = true;
    par[v] = p;

    for(int &x: adj[v]) {
        if(x != p) {
            if(vis[x]) {
             cycle_start = v;
                cycle_end = x;
                return true;
            }
            if(dfs(x, v, adj, vis, par)) {
                return true;
            }
        }
    }

    return false;
}

bool check_cycle(vector<vector<int>>& adj, int n, vector<int>& par) {
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            bool cycle = dfs(i, -1, adj, vis, par);
            if(cycle) return true;
        }
    }
    return false;
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

    vector<int> par(n+1, -1);
    bool cycle = check_cycle(adj, n, par);

    if(!cycle) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> ans;
        int x = cycle_start;
        while(x != cycle_end) {
            // cout << x << " ";
            ans.push_back(x);
            x = par[x];
        }
        // cout << cycle_end << " " << cycle_start << "\n";
        ans.push_back(cycle_end);
        ans.push_back(cycle_start);

        cout << ans.size() << "\n";
        for(int &x: ans) cout << x << " ";
        cout << "\n";
    }
    
    return 0;
}