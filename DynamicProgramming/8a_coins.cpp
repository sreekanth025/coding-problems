/*
Problem Link: https://www.codechef.com/problems/COINS
*/

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

map<int, int> result;

int solve(int n)
{
    if(n==0) return 0;
    if(result[n] != 0) return result[n];
    else
    {
        int p = solve(n/2)+solve(n/3)+solve(n/4); 
        result[n] = p>n ? p:n;
    }

    return result[n];
}

int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
/*
	int test_cases=1; 
	cin >> test_cases; 
*/

    result[0] = 0;
    result[1] = 1;

    int n;
	while(cin >> n)
        cout << solve(n) << "\n";
	return 0;
}
