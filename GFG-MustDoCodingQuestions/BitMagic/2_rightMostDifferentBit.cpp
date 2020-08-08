// Problem Link: https://practice.geeksforgeeks.org/problems/rightmost-different-bit/04

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// log(1e3) = 9.96
int solve() {
    int n, m; 
    cin >> m >> n; 
    
    for(int i=0; i<=10; i++) {
        if((n&(1<<i))^(m&(1<<i))) return i+1; 
    }
    
    return -1;
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        cout << solve() << "\n";
	return 0;
}