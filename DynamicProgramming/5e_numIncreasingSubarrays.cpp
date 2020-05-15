/*
Given an array A1, A2, ..., AN.
Count the number of subarrays of array A which are non-decreasing.
*/

// Problem link: https://www.codechef.com/problems/SUBINC
// Time Complexity: O(n)

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
    int n; 
    cin >> n;
    
    int arr[n]; 
    forn(n) cin >> arr[i]; 
    
    int count[n];
    memset(count, 0, sizeof(count)); 
    count[0] = 1; 
    
    for(rg int i=1; i<n; i++) 
        if(arr[i] >= arr[i-1]) count[i] = count[i-1]+1; 
        else count[i] =  1;
    
    for(int i=1; i<n; i++) count[i] += count[i-1];
    cout << count[n-1] << "\n";
}

int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_cases=1; 
	cin >> test_cases; 
	
	while(test_cases--)
        solve();
	return 0;
}
