#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int solve() {

    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for(int &x: coins) cin >> x;

    vector<int> dp(target+1);
    dp[0] = 1;

    for(int i=1; i<=target; i++) {
        for(int coin: coins) {
            if(i >= coin)
                dp[i] = (dp[i] + dp[i-coin])%mod;
        }
    }

    return dp[target];
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}