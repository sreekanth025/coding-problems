// Problem Link: https://codeforces.com/contest/1364/problem/B

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
#define mod 1e9 + 7
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define pb push_back
#define set0(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define nl "\n"
#define sp printf(" ")

void solve()
{
    int n; 
	cin >> n; 

	Vi arr(n, 0); 
	REP(i,0,n-1) cin >> arr[i]; 
	int count=0; 
	Vi result(n, 0); 
	result[count++]=arr[0]; 

	REP(i,1,n-2) 
		if((arr[i]-result[count-1])*(arr[i+1]-arr[i])<0) 
			result[count++]=arr[i];
	result[count++]=arr[n-1];
	cout << count << nl; 
	REP(i,0,count-1) cout << result[i] << " "; 
	cout << nl;
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	cin >> test_cases; 
	while(test_cases--)
        solve();
	return 0;
}