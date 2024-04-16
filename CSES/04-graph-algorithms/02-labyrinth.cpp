#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>  dx  {1,   -1,  0,    0 };
vector<int>  dy  {0,    0,  1,   -1 };
vector<char> dir {'D', 'U', 'R', 'L'};
unordered_map<char, int> dir_index = {
    {'D', 0}, {'U', 1}, {'R', 2}, {'L', 3}
};

int n, m;
vector<string> adj;

bool is_valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

pair<int, int> get_start() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(adj[i][j] == 'A')
                return {i, j};
        }
    }
    return {-1, -1};
}

int32_t main() {

    cin >> n >> m;
    adj.assign(n, "");
    for(string &x: adj) cin >> x;

    auto [sx, sy] = get_start();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    map<pair<int, int>, char> parent;
    bool found = false;
    pair<int, int> pos_b;
    queue<pair<int, int>> que;
    que.push({sx, sy});

    while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        if(adj[x][y] == 'B') {
            found = true;
            pos_b = {x, y};
            break;
        }

        for(int p=0; p<4; p++) {
            int px = x + dx[p];
            int py = y + dy[p];
            if(is_valid(px, py) && adj[px][py] != '#' && !vis[px][py]) {
                vis[px][py] = true;
                parent[{px, py}] = dir[p];
                que.push({px, py});
            }
        }
        
    }

    if(!found) {
        cout << "NO" << "\n";
    }
    else {
        string ans = "";
        auto [x, y] = pos_b;
        while(adj[x][y] != 'A') {
            ans.push_back(parent[{x, y}]);
            int cx = dx[dir_index[parent[{x, y}]]];
            int cy = dy[dir_index[parent[{x, y}]]];
            x -= cx;
            y -= cy;
        }

        reverse(ans.begin(), ans.end());

        cout << "YES\n";
        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
    
    return 0;
}