#include<bits/stdc++.h>
using namespace std;

#define rg register
#define In inline
#define ll long long
#define forn(n) for(rg int i=0; i<n; i++)
#define for1n(n) for(rg int i=1; i<=n; i++)
#define int long long
const ll inf = 0x3f3f3f3f3f3f3f3f;
#define mod 1e9 + 7

void solve()
{
    int n, m; 
    cin >> n >> m; 

    vector<int> inst(n+1, 0); 
    forn(m)
    {
        int v, u, w; 
        cin >> v >> u >> w; 
        
        inst[u] -= w; 
        inst[v] += w; 
    }

    int result = 0;
    forn(n+1) if(inst[i]>0) result += inst[i];
    cout << result << "\n";
}

int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_cases=1; 
	// cin >> test_cases; 
	
	while(test_cases--)
        solve();
	return 0;
}
