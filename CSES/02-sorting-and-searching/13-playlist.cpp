#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n;
    cin >> n;

    int x, last_repeated = 0, ans = 0;
    map<int, int> position;
    for(int i=1; i<=n; i++) {
        cin >> x;
        last_repeated = max(last_repeated, position[x]);
        ans = max(ans, i-last_repeated);
        position[x] = i;
    }
    
    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}