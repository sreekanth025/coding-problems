// Problem Link: https://codeforces.com/contest/1418/problem/C

#include<bits/stdc++.h>
using namespace std; 

#define ll long long
#define int long long
const int INF = 1e9+5;

int solve() {
    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) cin >> x; 

    vector<vector<int>> dp(n+1, vector<int>(2, INF));
    dp[0][1]=0;
    // dp[i][0] - minimum number of hard bosses for our friend, if we finished first i positions and the next turn is your's.
    // dp[i][0] - minimum number of hard bosses for our friend, if we finished first i positions and the next turn is friend's.

    for(int i=0; i<n; i++) {
        for(int p=0; p<2; p++) { 
            // p=0 => you, 
            // p=1 => friend.

            for(int fight=1; fight <= min(n-i, (ll)2); fight++) {
                int hard = arr[i] + (fight>1 ? arr[i+1]:0); 
                dp[i+fight][!p] = min(dp[i+fight][!p], dp[i][p] + p*hard);
                // when you fight (p=0), p*hard gives 0.
            } 
        }
    }

    return min(dp[n][0], dp[n][1]);
}

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    freopen("input.txt", "r", stdin);

    int test_cases=1;
    cin >> test_cases; 
    while(test_cases--) {
    cout << solve() << "\n";
        // solve();
    }
    return 0; 
}