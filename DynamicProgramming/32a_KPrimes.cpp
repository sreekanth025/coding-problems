// Problem Link: https://www.codechef.com/LRNDSA07/problems/KPRIME

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
#define mod 1e9 + 7
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define pb push_back
#define set0(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define nl "\n"
#define sp printf(" ")

const int MAXN = 1e5+1;
const int MAXK = 5;

Vi uniquePrimeFactors(MAXN, 0);
int kp[MAXN][MAXK+1];

void precompute()
{
    REP(i,2,MAXN-1)
        if(uniquePrimeFactors[i]==0)
            for(int j=i; j<MAXN; j+=i)
                uniquePrimeFactors[j]++;
    
    REP(i,2,MAXN-1)
        REP(j,1,MAXK)
            kp[i][j] = kp[i-1][j] + (uniquePrimeFactors[i]==j ? 1:0); 
}

int solve()
{
    int a, b, k; 
    cin >> a >> b >> k; 
    return kp[b][k]-kp[a-1][k];
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	cin >> test_cases; 
	
    precompute(); 
	while(test_cases--)
        cout << solve() << nl;
	return 0;
}