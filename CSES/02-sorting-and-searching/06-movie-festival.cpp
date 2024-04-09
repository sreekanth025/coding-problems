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
        arr.push_back({a, b});
    }

    // sorting based on ending times;
    sort(arr.begin(), arr.end(), [&](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    });

    int ans = 0;
    int prev_end = -1;

    for(auto [start, end]: arr) {
        if(start >= prev_end) {
            ans++;
            prev_end = end;
        }
    }

    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}