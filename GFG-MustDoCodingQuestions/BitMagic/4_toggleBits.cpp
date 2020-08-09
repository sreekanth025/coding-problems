// Problem Link: https://practice.geeksforgeeks.org/problems/toggle-bits-given-range/0

#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    int n, l, r; 
    cin >> n >> l >> r; 
    
    int add = 0;    
    for(int i=l-1; i<=r-1; i++) {
        if(n&(1<<i)) add -= (1<<i); 
        else add += (1<<i); 
    }
    
    cout << n + add << "\n";
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        solve();
	return 0;
}