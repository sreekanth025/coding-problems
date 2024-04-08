#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve1() {

    int n;
    cin >> n;

    unordered_set<int> hash_set;
    int x;

    for(int i=0; i<n; i++) {
        cin >> x;
        hash_set.insert(x);
    }
    return hash_set.size();
}

int solve2() {

    int n;
    cin >> n;

    set<int> sett;
    int x;

    for(int i=0; i<n; i++) {
        cin >> x;
        sett.insert(x);
    }
    return sett.size();
}

int solve3() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    int ans = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] != arr[i-1]) ans++;
    }

    return ans;
}

int32_t main() {
    // cout << solve1() << "\n"; // TLE
    // cout << solve2() << "\n"; // Accepted
    cout << solve3() << "\n"; // Accepted
    return 0;
}