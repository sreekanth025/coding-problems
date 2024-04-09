#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {

    int n, m;
    cin >> n >> m;

    int x;
    multiset<int> ms;

    for(int i=0; i<n; i++) {
        cin >> x;
        ms.insert(x);
    }

    for(int i=0; i<m; i++) {
        cin >> x;
        auto it = ms.upper_bound(x);

        if(it == ms.begin()) {
            cout << "-1" << "\n";
        } 
        else {
            it--;
            cout << *it << "\n";
            ms.erase(it);
        }
    }

    return 0;
}