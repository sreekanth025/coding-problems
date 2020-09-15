// Problem Link: https://codeforces.com/contest/1418/problem/A

#include<bits/stdc++.h>
using namespace std; 
#define int long long
 
int solve() {
    int x, y, k;
    cin >> x >> y >> k;
 
    long double num = k*(1+y)-1; 
    long double den = x-1; 
 
    int res = ceil(num/den); 
    return res+k;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
 
    // freopen("input.txt", "r", stdin);
 
    int test_cases=1;
    cin >> test_cases; 
    while(test_cases--) {
        cout << solve() << "\n";
    }
    return 0; 
}