// Problem Link: https://codeforces.com/contest/1367/problem/B

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
const ll mod = 1e9 + 7;
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

    int arr[n]; 
    forn(i,n) cin >> arr[i]; 

    int tb_even_pos=0, tb_odd_pos=0;
    REP(i,0,n-1)
    {
        if(i%2 == arr[i]%2) continue;
        else if(arr[i]%2==1) tb_odd_pos++; 
        else tb_even_pos++;
    } 

    if(tb_even_pos==tb_odd_pos) cout << tb_even_pos << nl;
    else cout << "-1\n"; 
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