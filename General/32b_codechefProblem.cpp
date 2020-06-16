// Problem Link: https://www.codechef.com/LRNDSA07/problems/FROGV

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
    int n,k,p; 
    cin>>n>>k>>p; 
    
    vector<pair<int,int>> arr(n); 
    REP(i,0,n-1) 
    {
        cin>>arr[i].first; 
        arr[i].second=i;
    }
    
    int comp=0, last=0, component[n]; 
    sort(all(arr)); 
    
    for(auto x: arr)
    {
        if(x.first-last <= k)
        {
            last=x.first; 
            component[x.second]=comp; 
        }
        else
        {
            last=x.first; 
            component[x.second]=++comp;
        }
    }
    
    int a, b;
    while(p--)
    {
        cin>>a>>b; 
        a--; b--;
        if(component[a]==component[b]) cout << "Yes\n"; 
        else cout<<"No\n";
    }
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	// cin >> test_cases; 
	while(test_cases--)
        solve();
	return 0;
}