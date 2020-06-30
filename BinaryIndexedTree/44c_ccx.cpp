// problem Link: https://www.codechef.com/ENJU2020/problems/ECJN208

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
#define sp " "

Vi BIT; 
int _BITparent(int x){ return x - (x&-x); }
int _BITnext(int x) { return x + (x&-x); }

int _sum(int x) {
    int sum=0; 
    while(x > 0) {
        sum +=  BIT[x];
        x = _BITparent(x); 
    }
    return sum; 
}

void update(int i, int val) {
    // val = val - _sum(i) + _sum(i-1); 
    while(i < BIT.size()) {
        BIT[i] += val; 
        i = _BITnext(i); 
    }
}

void solve()
{
    int n;
    cin >> n; 
    
    BIT.assign(n+1, 0);
    int p; 
    
    forn(i, n) {
        cin >> p;
        update(i+1, p); 
    }
    
    int q;
    int a, b, c;
    cin >> q; 
    while(q--) {
        cin >> a >> b >> c; 
        if(!a) {
            update(b, c); 
        }
        else {
            cout << ceil((double)(_sum(c)-_sum(b-1)) / (c-b+1)) << nl; 
        }
    }
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	// cin >> test_cases; 
	while(test_cases--)
        solve();
        // cout << solve() << nl;
	return 0;
}