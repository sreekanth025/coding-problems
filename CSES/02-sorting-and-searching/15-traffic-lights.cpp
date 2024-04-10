#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve1() {
    int x, n;
    cin >> x >> n;

    set<int> lights;
    lights.insert(0);
    lights.insert(x);

    multiset<int> distances;
    distances.insert(x);

    int p;
    for(int i=0; i<n; i++) {
        cin >> p;
        if(p != 0 && p != x) {
            lights.insert(p);
            auto it = lights.find(p);

            it--;
            int left = p - (*it);
            it++;

            it++;
            int right = (*it) - p;
            it--;

            int prev_dist = left + right;
            distances.erase(distances.find(prev_dist));
            distances.insert(left);
            distances.insert(right);

        }
        cout << *distances.rbegin() << " ";
    }

    cout << "\n";
}

int32_t main() {
    solve1();
}