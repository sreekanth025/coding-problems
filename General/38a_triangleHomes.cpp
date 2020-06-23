// Problem Link: https://www.codechef.com/viewsolution/34658090

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
const ll MAXN = 1e6+5; 

void solve()
{
    int n;  
    cin >> n; 

    Vi prex(MAXN, 0), prey(MAXN, 0); 
    int x[3], y[3]; 

    forn(i, n)
    {
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2]; 
        sort(x, x+3); 
        sort(y, y+3); 
         
        prex[x[0]+1]++; prex[x[2]]--; 
        prey[y[0]+1]++; prey[y[2]]--;
    }
    
    REP(i,1,MAXN-1)
    {
        prex[i]+=prex[i-1]; 
        prey[i]+=prey[i-1]; 
    }

/*
    cout << "debug: \n"; 
    for(auto home: arr)
        cout << home.xmin << " " << home.xmax << " " << home.ymin << " " << home.ymax << nl;
    cout << "----------\n";
*/
    int m; 
    cin >> m; 
    while(m--)
    {
        int c, count=0; 
        char axis, _eq; 
        cin >> axis >> _eq >> c; 

        if(axis == 'x') cout << prex[c] << nl;
        else cout << prey[c] << nl;
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

/*
3
1 0 0 2 2 2
1 3 3 5 4 0 
5 4 4 5 4 4
3
x = 1
x = 2
y = 1
*/

/* Solution: 1 1 2 */