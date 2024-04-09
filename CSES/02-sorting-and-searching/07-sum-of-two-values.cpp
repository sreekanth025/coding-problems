#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve1() {

    int n, x;
    cin >> n >> x;

    // 1-based indexing
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin >> arr[i];

    map<int, int> index;
    for(int i=1; i<=n; i++) {
        int target = x - arr[i];
        if(index[target] != 0) {
            cout << i << " " << index[target] << "\n";
            return;
        }
        index[arr[i]] = i;
    }

    cout << "IMPOSSIBLE\n";
    return;
}

void solve2() {

    int n, x;
    cin >> n >> x;

    int p;
    vector<pair<int, int>> arr;
    for(int i=1; i<=n; i++) {
        cin >> p;
        arr.push_back({p, i});
    }

    sort(arr.begin(), arr.end());
    int i=0, j=n-1;
    while(i < j) {
        int sum = arr[i].first + arr[j].first;
        if(sum == x) {
            cout << arr[i].second << " " << arr[j].second << "\n";
            return;
        }
        else if(sum < x) i++;
        else j--;
    }

    cout << "IMPOSSIBLE\n";
    return;
}

int32_t main() {
    // solve1();
    solve2();
    return 0;
}