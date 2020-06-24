// Problem Link: https://www.codechef.com/problems/NUMFACT

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

void _helper(int n, unordered_map<int, int>& count)
{
    while(n%2 == 0)
    {
        count[2]++; 
        n/=2; 
    }
    
    for(int i=3; i*i <= n; i+=2)
    {
        while(n%i == 0)
        {
            count[i]++; 
            n/=i;
        }
    }
    
    if(n>2) count[n]++; 
}

int solve()
{
    int n;
    cin >> n;
    
    int arr[n]; 
    forn(i,n) cin >> arr[i]; 
    
    unordered_map<int, int> count; 
    forn(i,n) _helper(arr[i], count); 
    
    int result=1; 
    for(auto x: count)
        result = result*(x.second + 1);
        
    return result;
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