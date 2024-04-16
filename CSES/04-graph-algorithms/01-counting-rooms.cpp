#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dx {1, -1, 0,  0};
vector<int> dy {0,  0, 1, -1};


int n, m;
vector<string> adj;
vector<vector<bool>> vis;

bool is_valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int i, int j) {
    vis[i][j] = true;
    for(int p=0; p<4; p++) {
        int px = i + dx[p];
        int py = j + dy[p];
        if(is_valid(px, py) && adj[px][py] == '.' && !vis[px][py])
            dfs(px, py);
    }
}

int32_t main() {
    
    cin >> n >> m;
    adj.assign(n, "");
    for(string &x: adj) cin >> x;

    vis.assign(n, vector<bool>(m, false));
    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!vis[i][j] && adj[i][j] == '.') {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}