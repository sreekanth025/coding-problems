#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;

    int ans = 0;
    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            ans += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
        }
    }

    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}