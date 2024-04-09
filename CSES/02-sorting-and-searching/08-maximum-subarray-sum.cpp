#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;

    int current_sum = arr[0], ans = arr[0];
    for(int i=1; i<n; i++) {
        if(current_sum < 0) current_sum = 0;
        current_sum += arr[i];
        ans = max(ans, current_sum);
    }

    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}