#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve1() {

    int n;
    cin >> n;

    int x, current_sum = 0;
    for(int i=0; i<n-1; i++) {
        cin >> x;
        current_sum += x;
    }

    int n_sum = (n * (n+1))/2;
    return n_sum - current_sum;
}

int32_t main() {
    cout << solve1() << "\n";
    return 0;
}