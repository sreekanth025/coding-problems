// Problem Link: https://practice.geeksforgeeks.org/problems/find-first-set-bit/0

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// log(1e6) = 19.93
int solve() {
    int n; 
    cin >> n; 
    for(int i=0; i<=20; i++) {
        if(n&(1<<i)) return i+1; 
    }
    
    return 0;
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        cout << solve() << "\n";
	return 0;
}