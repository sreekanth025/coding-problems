// Problem Links: https://www.codechef.com/LRNDSA07/problems/CDQU5

#include<bits/stdc++.h>
using namespace std;

#define rg register
#define In inline
#define ll long long
#define int long long

#define REP(i,start,end) for(rg int i=start; i<=end; i++)
#define RREP(i,end,start) for(rg int i=end; i>=start; i--)
#define forn(i, n) for(rg int i=0; i<n; i++)

#define eps 1e-9
const ll mod = 1e9 + 9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define pb push_back
#define set0(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define nl "\n"
#define sp printf(" ")

Vi dp(1000005, -1); 

int solve(int n)
{
    if(dp[n] != -1) return dp[n]; 
    
    dp[n] = (solve(n-2)+solve(n-3))%mod;
    return dp[n];
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	cin >> test_cases; 
	
	dp[0]=dp[1]=0; 
	dp[2]=dp[3]=1; 
	
	int n;
	while(test_cases--){
	    cin >> n;
        cout << solve(n) << nl;
	}
	return 0;
}