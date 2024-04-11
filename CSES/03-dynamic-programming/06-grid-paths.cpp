#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int solve1() {

    int n;
    cin >> n;

    vector<string> grid(n);
    for(string &s: grid) cin >> s;

    if(grid[0][0] == '*') return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;

    for(int i=1; i<n; i++) 
        if(grid[i][0] == '.') dp[i][0] = 1;
        else break;

    for(int j=1; j<n; j++)
        if(grid[0][j] == '.') dp[0][j] = 1;
        else break;

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
    }
    
    return dp[n-1][n-1];
}

// can do space optimization

int32_t main() {
    cout << solve1() << "\n";
    return 0;
}