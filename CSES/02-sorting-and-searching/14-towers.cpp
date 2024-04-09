#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    int x;
    vector<int> arr;
    for(int i=0; i<n; i++) {
        cin >> x;
        if(arr.empty() || x >= arr.back()) arr.push_back(x);
        else {
            auto it = upper_bound(arr.begin(), arr.end(), x);
            *it = x;
        }
    }

    return arr.size();
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}