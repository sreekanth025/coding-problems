// Problem Link: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not/0

#include <iostream>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    int n, k; 
    cin >> n >> k; 
    
    if(n&(1<<k)) cout << "Yes\n";
    else cout << "No\n"; 
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        solve();
	return 0;
}