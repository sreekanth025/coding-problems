// Problem Link: https://codeforces.com/contest/1364/problem/A

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

int solve()
{
    int n, x; 
	cin >> n >> x; 

	Vi arr(n, 0); REP(i,0,n-1) cin>>arr[i]; 
	int sum=0; REP(i,0,n-1) sum+=arr[i];

	int left=0, right=n-1; 
	while(left<=right)
	{
		if(sum%x) return right-left+1; 
		if(arr[left]%x || arr[right]%x) return max(right, n-left-1); 

		sum-=arr[left]; 
		sum-=arr[right]; 
		left++; right--; 
	}
	return -1;
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	cin >> test_cases; 
	while(test_cases--)
        cout << solve() << nl;
	return 0;
}