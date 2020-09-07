#include <bits/stdc++.h>
using namespace std;

int solve() {
    int m, n; 
    cin >> m; 
    
    vector<int> coins(m); 
    for(int i=0; i<m; i++) cin>>coins[i]; 
    cin >> n; 
    
    vector<int> dp(n+1, 0); 
    dp[0]=1; 
    for(int x: coins) {
        for(int i=1; i<=n; i++) {
            if(x <= i) dp[i] += dp[i-x]; 
        }
    }
    
    return dp[n]; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    
    int test_cases=1; 
    cin >> test_cases;
    
    while(test_cases--) {
        cout << solve() << "\n"; 
    }
	return 0;
}