#include <bits/stdc++.h>
using namespace std;

int solve() {
    
    int n, w; 
    cin >> n >> w; 
    
    int val[n], wei[n];
    for(int i=0; i<n; i++) cin >> val[i]; 
    for(int i=0; i<n; i++) cin >> wei[i];
    
    int dp[n+1][w+1]; 
    
    // dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wei[i-1]])
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=w; j++) {
            if(i==0 || j==0) dp[i][j]=0;
            
            else {
                if(wei[i-1] > j) dp[i][j] = dp[i-1][j]; 
                else dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i-1][j-wei[i-1]]); 
            }
        }
    }
    
    return dp[n][w]; 
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