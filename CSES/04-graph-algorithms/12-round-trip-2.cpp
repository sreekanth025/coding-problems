#include<bits/stdc++.h>
using namespace std;
#define int long long

int cycle_start, cycle_end;

bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& in_stack, vector<int>& par, int v) {

    vis[v] = true;
    in_stack[v] = true;

    for(int &x: adj[v]) {
        if(vis[x]) {
            if(in_stack[x]) {
                cycle_start = x;
                cycle_end = v;
                return true;
            }
        } 
        else {
            par[x] = v;
            bool cycle = dfs(adj, vis, in_stack, par, x);
            if(cycle) return true;
        }
    }

    in_stack[v] = false;
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
    }

    vector<bool> vis(n+1, false);
    vector<bool> in_stack(n+1, false);
    vector<int> par(n+1, -1);

    bool cycle = false;
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(adj, vis, in_stack, par, i)) {
                cycle = true;
                break;
            }
        }
    }

    if(!cycle) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> path;

        int x = cycle_end;
        while(x != cycle_start) {
            path.push_back(x);
            x = par[x];
        }
        path.push_back(cycle_start);
        path.push_back(cycle_end);
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for(int &e: path) cout << e << " ";
        cout << "\n";
    }
    
    return 0;
}