// Problem Link: https://codeforces.com/contest/1418/problem/B

#include<bits/stdc++.h>
using namespace std; 
#define int long long

void solve() {
    int n; 
    cin >> n;

    vector<int> inp(n), mask(n);
    for(int &x: inp) cin >> x;
    for(int &x: mask) cin >> x;  

    vector<int> free; 
    for(int i=0; i<n; i++) {
        if(!mask[i]) free.push_back(inp[i]);
    } 
    sort(free.begin(), free.end(), greater<int>());

    int fp=0; 
    for(int i=0; i<n; i++) {
        if(mask[i]) cout << inp[i] << " ";
        else cout << free[fp++] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    freopen("input.txt", "r", stdin);

    int test_cases=1;
    cin >> test_cases; 
    while(test_cases--) {
        // cout << solve() << "\n";
        solve();
    }
    return 0; 
}