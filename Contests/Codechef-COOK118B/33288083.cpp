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

string solve()
{
    int n;
    cin >> n;

    int arr[n];
    forn(n) cin >> arr[i];

    unordered_map<int, bool> ingredient;
    unordered_map<int, bool> count; 

    ingredient[arr[0]] = true;
    int temp_count = 1;

    for(int i=1; i<n; i++)
    {
        if(arr[i] == arr[i-1])
        {
            temp_count++;
        }
        else
        {
            if(ingredient[arr[i]]) return "NO";

            if(count[temp_count]) return "NO"; 
            else count[temp_count]=true;

            ingredient[arr[i]] = true;
            temp_count = 1;
        }
    }

    if(count[temp_count]) return "NO";
    return "YES";
}

int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_cases=1; 
	cin >> test_cases; 
	
	while(test_cases--)
        cout << solve() << "\n";
	return 0;
}
