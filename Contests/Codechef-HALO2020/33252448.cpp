#include<bits/stdc++.h>
using namespace std;

#define rg register
#define In inline
#define ll long long
#define forn(n) for(rg int i=0; i<n; i++)
#define for1n(n) for(rg int i=1; i<=n; i++)
#define int long long
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

int fact[500005];
vector<int> modinv(500005, -1); 

int powr(int a, int n)
{
    a %= mod;
    int result = 1; 
    while(n)
    {
        if(n&1) result = result*a%mod; 
        a = a*a%mod; 
        n /= 2;
    }
    return result%mod; 
}

int ncr(int n, int r)
{
    if(modinv[r] ==  -1) modinv[r] = powr(fact[r], mod-2); 
    if(modinv[n-r] == -1) modinv[n-r] = powr(fact[n-r], mod-2);
    return fact[n]*modinv[r]%mod * modinv[n-r]%mod; 
}

void solve()
{
    int n, l, k, result=0;  
    cin >> n >> l >> k; 

    vector<int> arr(n); 
    forn(n) cin >> arr[i]; 
    sort(arr.begin(), arr.end()); 

    forn(n-l+1)
    {
        int pos = upper_bound(arr.begin(), arr.end(), arr[i]+k) - arr.begin()-1;
        if(pos-i+1 >= l)
            result = (result + ncr(pos-i, l-1))%mod;
    }
    cout << result << "\n";
}

int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_cases=1; 
	// cin >> test_cases; 
	
    fact[0] = 1;
    fact[1] = 1;
    for(rg int i=2; i<500005; i++)
        fact[i] = (fact[i-1]*i)%mod;

	while(test_cases--)
        solve();
	return 0;
}
