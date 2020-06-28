// Problem Link: https://www.codechef.com/problems/MAXAND18

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

bool compare(pair<int,int> a, pair<int, int> b)
{
    if(a.first == b.first) return a.second < b.second; 
    return a.first > b.first; 
}

void solve()
{
    int n, k;
    cin >> n >> k;
    
    int arr[n]; 
    forn(i,n) cin >> arr[i]; 
    
    vector<pair<int, int>> foo; 
    forn(i, 31) foo.pb({0, i});
    
    forn(i,n)
        forn(j, 31) foo[j].first += (arr[i] & (1<<j)); 
        
    sort(all(foo), compare); 
    
    int result  = 0; 
    forn(i, k)
        result += (1 << foo[i].second); 
    
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