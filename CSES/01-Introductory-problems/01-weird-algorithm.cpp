#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

    int n;
    cin >> n;

    while(n != 1) {
        cout << n << " ";
        if(n&1) n = 1 + 3*n;
        else n /= 2;
    }
    cout << 1 << "\n";

    return;
}

int32_t main() {
    solve();
    return 0;
}

// g++-11 -o program 01-weird-algorithm.cpp && ./program