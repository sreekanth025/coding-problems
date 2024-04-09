#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {

    int n, m;
    cin >> n >> m;

    // 1-based indexing
    vector<int> arr(n+1, 0);
    for(int i=1; i<=n; i++) cin >> arr[i];

    vector<int> position(n+1, 0);
    for(int i=1; i<=n; i++) {
        position[arr[i]] = i;
    }

    int inversions = 0;
    for(int i=2; i<=n; i++) {
        if(position[i] < position[i-1]) 
            inversions++;
    }

    while(m--) {

        int a, b;
        cin >> a >> b;

        int e1 = arr[a];
        int e2 = arr[b];

        set<pair<int, int>> affecting_pairs;
        if(e1 != 1) affecting_pairs.insert({e1-1, e1});
        if(e1 != n) affecting_pairs.insert({e1, e1+1});
        if(e2 != 1) affecting_pairs.insert({e2-1, e2});
        if(e2 != n) affecting_pairs.insert({e2, e2+1});

        // if there is an existing inversion, remove it from total count
        for(auto [x, y]: affecting_pairs) {
            if(position[y] < position[x]) inversions--;
        }

        // swap the elements and update their positions
        arr[a] = e2;
        arr[b] = e1;
        position[e2] = a;
        position[e1] = b;

        // check for new inversions
        for(auto [x, y]: affecting_pairs) {
            if(position[y] < position[x]) inversions++;
        }

        // number of passes required = inversions + 1;
        cout << inversions+1 << "\n";
    }

    return 0;
}