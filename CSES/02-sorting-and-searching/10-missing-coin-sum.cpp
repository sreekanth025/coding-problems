#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    int target = 1;
    for(int &x: arr) {
        // if we can achieve all numbers till target, 
        // then we can achieve all numbers till target + x using the new element x;
        if(x <= target)
            target += x;
        else break;
    }

    return target;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}