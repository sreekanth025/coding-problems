#include<bits/stdc++.h>
using namespace std;
#define int long long

unordered_map<int, int> cache;

int solve(int n) {
    if(n == 0) return 0;
    if(cache[n] != 0) return cache[n];
    
    int ans = 1e9;
    int copy_n = n;
    
    while(copy_n != 0) {
        int d = copy_n % 10;
        copy_n /= 10;
        if(d != 0) ans = min(ans, 1 + solve(n-d));
    }
    
    cache[n] = ans;
    return ans;
}

int32_t main() {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}