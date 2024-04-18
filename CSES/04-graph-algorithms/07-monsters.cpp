#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e9;
vector<int> dx {1, -1, 0,  0};
vector<int> dy {0,  0, 1, -1};
vector<char> dir{'D', 'U', 'R', 'L'};

bool is_valid(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool is_exit(int x, int y, int n, int m) {
    return x == 0 || x == n-1 || y==0 || y==m-1;
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<string> adj(n);
    for(string &x: adj) cin >> x;

    pair<int, int> start;
    vector<pair<int, int>> monsters;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(adj[i][j] == 'M') {
                monsters.push_back({i, j});
            }
            else if(adj[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    if(is_exit(start.first, start.second, n, m)) {
        cout << "YES\n";
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> m_time(n, vector<int>(m, inf));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    queue<tuple<int, int, int>> q;
    for(auto [x, y]: monsters) {
        q.push({x, y, 0});
        m_time[x][y] = 0;
        vis[x][y] = true;
    }

    while(!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();
        for(int p=0; p<4; p++) {
            int px = x + dx[p];
            int py = y + dy[p];
            if(is_valid(px, py, n, m) && (adj[px][py] != '#') && !vis[px][py]) {
                m_time[px][py] = t+1;
                vis[px][py] = true;
                q.push({px, py, t+1});
            }
        }
    }

    vis.assign(n, vector<bool>(m, false));
    q.push({start.first, start.second, 0});
    vis[start.first][start.second] = true;

    map<pair<int, int>, pair<int, int>> par;
    map<pair<int, int>, char> step;
    bool found = false;
    pair<int, int> exit;

    while(!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();
        for(int p=0; p<4; p++) {
            int px = x + dx[p];
            int py = y + dy[p];
            if(is_valid(px, py, n, m) && adj[px][py] == '.' && !vis[px][py] && m_time[px][py] > t+1) {
                vis[px][py] = true;
                q.push({px, py, t+1});
                par[{px, py}] = {x, y};
                step[{px, py}] = dir[p];

                if(is_exit(px, py, n, m)) {
                    found = true;
                    exit = {px, py};
                }
            }
            if(found) break;
        }
    }

    if(found) {
        cout << "YES\n";
        string ans = "";
        
        while(exit != start) {
            ans.push_back(step[exit]);
            exit = par[exit];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        cout << ans << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}