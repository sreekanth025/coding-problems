#include<bits/stdc++.h>
using namespace std;
// #define int long long

int solve1() {
    
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for(int &e: prices) cin >> e;
    for(int &e: pages) cin >> e;

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= prices[i-1]) dp[i][j] = max(dp[i][j], pages[i-1] + dp[i-1][j-prices[i-1]]);
        }
    }

    return dp[n][x];
}

int solve2() {
    
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for(int &e: prices) cin >> e;
    for(int &e: pages) cin >> e;

    vector<vector<int>> dp(2, vector<int>(x+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            dp[i%2][j] = dp[(i-1)%2][j];
            if(j >= prices[i-1]) dp[i%2][j] = max(dp[i%2][j], pages[i-1] + dp[(i-1)%2][j-prices[i-1]]);
        }
    }

    return dp[n%2][x];
}

int solve3() {
    
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for(int &e: prices) cin >> e;
    for(int &e: pages) cin >> e;

    vector<int> prev(x+1, 0), cur(x+1, 0);
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=x; j++) {
            cur[j] = prev[j];
            if(j >= prices[i-1]) cur[j] = max(cur[j], pages[i-1] + prev[j-prices[i-1]]);
        }
        prev = cur;
    }

    return cur[x];
}

int solve4() {
    
    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for(int &e: prices) cin >> e;
    for(int &e: pages) cin >> e;

    vector<int> dp(x+1, 0);
    
    for(int i=1; i<=n; i++) {
        for(int j=x; j>=1; j--) {
            if(j >= prices[i-1]) dp[j] = max(dp[j], pages[i-1] + dp[j-prices[i-1]]);
        }
    }

    return dp[x];
}

int32_t main() {
    // cout << solve1() << "\n";
    // cout << solve2() << "\n";
    // cout << solve3() << "\n";
    cout << solve4() << "\n";
    return 0;
}