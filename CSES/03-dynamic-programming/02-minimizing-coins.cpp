#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n, target;
    cin >> n >> target;

    vector<int> coins(n);
    for(int &x: coins) cin >> x;

    vector<int> dp(target+1, 1e9);
    dp[0] = 0;
    for(int coin: coins) 
        if(coin <= target) 
            dp[coin] = 1;

    for(int i=1; i<=target; i++) {
        for(int coin: coins) {
            if(i >= coin)
                dp[i] = min(dp[i], 1+dp[i-coin]);
        }
    }

    return (dp[target] < 1e9) ? dp[target] : -1;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}