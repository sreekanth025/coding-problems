// Problem Link: https://practice.geeksforgeeks.org/problems/power-of-2/0

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

string solve() {
    ll n; 
    cin >> n; 
    
    // log(10^18) = 59.79
    for(int i=0; i<=60; i++) {
        if(n&( ( (ll)1 ) << i )) {
            if(n-(((ll)1)<<i) == 0) return "YES"; 
            else return "NO";
        }
    }
    
    return "NO";
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        cout << solve() << "\n";
	return 0;
}