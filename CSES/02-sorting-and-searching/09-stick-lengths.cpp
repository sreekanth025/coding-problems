#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    int median = (n&1) ? arr[n/2] : (arr[n/2] + arr[n/2 - 1])/2;
    int ans = 0;
    for(int &x: arr) 
        ans += abs(x-median);

    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}