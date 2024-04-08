#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> desired(n), apartments(m);
    for(int &x: desired) cin >> x;
    for(int &x: apartments) cin >> x;

    sort(desired.begin(), desired.end());
    sort(apartments.begin(), apartments.end());

    int i=0, j=0, ans=0;
    while(i<n && j<m) {
        if(desired[i]-k <= apartments[j] && apartments[j] <= desired[i]+k) {
            i++, j++, ans++;
        }
        else {
            if(desired[i] < apartments[j]) i++;
            else j++;
        }
    }

    return ans;
}

int32_t main() {

    cout << solve() << "\n";
    return 0;
}