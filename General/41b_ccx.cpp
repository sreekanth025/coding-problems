// Problem Link: https://www.codechef.com/LRNDSA02/problems/NOTALLFL

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
    int n, k; 
    cin >> n >> k; 
    
    Vi arr(n); 
    forn(i,n) cin >> arr[i]; 
    
    int left=0, right=0; 
    unordered_map<int, int> count; 
    int present = 0, result=0; 
    
    while(right < n)
    {
        if(count[arr[right]]==0 && present==(k-1))
        {
            count[arr[left]]--; 
            if(count[arr[left]]==0) present--; 
            left++;
            continue;
        }
        
        count[arr[right]]++; 
        if(count[arr[right]]==1) present++; 
        
        result = max(result, right-left+1);
        right++;
    }
    
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