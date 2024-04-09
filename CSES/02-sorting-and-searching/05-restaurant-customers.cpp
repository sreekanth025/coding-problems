#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    int a, b;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }

    sort(arr.begin(), arr.end());
    int count = 0, ans = 0;

    for(auto [_, j]: arr) {
        count += j;
        ans = max(ans, count);
    }

    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}