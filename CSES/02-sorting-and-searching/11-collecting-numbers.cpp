#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    int x;
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++) {
        cin >> x;
        arr.push_back({x, i});
    }

    sort(arr.begin(), arr.end());
    int ans = 1;
    for(int i=1; i<n; i++) {
        if(arr[i].second < arr[i-1].second) ans++;
    }

    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}