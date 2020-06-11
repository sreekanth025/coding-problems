/*
Find the minimum area of a square land on which you can place two identical rectangular a×b houses. 
The sides of the houses should be parallel to the sides of the desired square land
*/

// Problem link: https://codeforces.com/contest/1360/problem/A

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
    int a, b; 
	cin >> a >> b; 
 
	if(b>a) swap(a, b); 
	int x = max(a, 2*b); x = x*x; 
	int y = max(2*a, b); y = y*y; 
	int z = (a+b)*(a+b); 
 
	int result = min(x, y); 
	result = min(result, z); 
	cout << result << nl;
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