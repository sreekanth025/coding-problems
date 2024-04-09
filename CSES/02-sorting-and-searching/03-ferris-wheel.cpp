#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for(int &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    int ans = 0;
    int i=0, j=n-1;

    while(i <= j) {
        if(arr[i] + arr[j] <= x) {
            i++, j--;
        }
        else {
            j--;
        }
        ans++;
    }
    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}