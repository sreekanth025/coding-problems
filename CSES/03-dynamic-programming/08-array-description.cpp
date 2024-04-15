#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int32_t main() {

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;

    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    if(arr[0] == 0) {
        for(int j=1; j<=m; j++) {
            dp[0][j] = 1;
        }
    }
    else {
        dp[0][arr[0]] = 1;
    }


    for(int i=1; i<n; i++) {
        if(arr[i] != 0) {
            int val = arr[i];
            for(int k: {val-1, val, val+1}) {
                if(1 <= k && k <= m) {
                    dp[i][val] = (dp[i][val] + dp[i-1][k])%mod;
                }
            }
        }
        else {
            for(int val = 1; val <= m; val++) {
                for(int k: {val-1, val, val+1}) {
                    if(1 <= k && k <= m) {
                        dp[i][val] = (dp[i][val] + dp[i-1][k])%mod;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int &x: dp[n-1]) 
        ans = (ans+x)%mod;
    cout << ans << "\n";

    return 0;
}