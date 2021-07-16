#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://cses.fi/problemset/task/1094

#define int long long

// O(n)
void method_1() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    int ans=0;
    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) {
            ans += (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
    }

    cout << ans << "\n";
}

int32_t main() {

    method_1();
    return 0;
}