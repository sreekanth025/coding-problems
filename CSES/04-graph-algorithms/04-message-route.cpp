#include<bits/stdc++.h>
using namespace std;
#define int long long

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

    vector<bool> vis(n+1, false);
    vis[1] = true;
    vector<int> par(n+1, -1);
    queue<int> q;
    q.push(1);

    bool found = false;
    while(!q.empty()) {

        int top = q.front();
        q.pop();

        if(top == n) {
            found = true;
            break;
        }

        for(int &x: adj[top]) {
            if(!vis[x]) {
                q.push(x);
                par[x] = top;
                vis[x] = true;
            }
        }
    }

    if(found) {
        vector<int> path;
        int x = n;
        while(x != -1) {
            path.push_back(x);
            x = par[x];
        }
    
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for(int &i: path) cout << i << " ";
        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
}