// Problem Link: https://practice.geeksforgeeks.org/problems/set-kth-bit/0

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    int n, k; 
    cin >> n >> k; 
    
    if(! (n&(1<<k))) n+=(1<<k);
    cout << n << "\n";
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        solve();
	return 0;
}