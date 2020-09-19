// Problem Link: https://www.codechef.com/submit/CHEFNWRK

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

int solve()
{
    int n, k;
    cin >> n >> k; 
    
    vector<int> arr(n); 
    for(int &x: arr) cin >> x; 
    
    int res=0; 
    int tmp=0, i=0;
    while(i<n) {
        
        if(arr[i] > k) return -1;
        
        if(arr[i]+tmp > k) {
            res++;
            tmp = arr[i];
            i++;
            continue;
        }
        
        tmp += arr[i]; 
        i++;
    }
    
    if(tmp > 0) res++; 
    return res;
}

int32_t main() {
	// your code goes here
    fast;

    //freopen("input.txt", "r", stdin);

	int test_cases=1; 
	cin >> test_cases; 
	while(test_cases--)
        //solve();
        cout << solve() << nl;
	return 0;
}