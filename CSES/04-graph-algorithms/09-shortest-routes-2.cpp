#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e18;

int32_t main() {

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dp(n+1, vector<int>(n+1, inf));
    for(int i=1; i<=n; i++) dp[i][i] = 0;

    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());
    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(dp[a][b] > c) {
            dp[a][b] = c;
            dp[b][a] = c;
        }
    }

    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(q--) {
        int a, b;
        cin >> a >> b;
        int ans = (dp[a][b] != inf) ? dp[a][b] : -1;
        cout << ans << "\n";
    }

    return 0;
}