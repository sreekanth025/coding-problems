#include<bits/stdc++.h>
using namespace std;
#define int long long

int get(int x, int y) {

    if(x > y) {
        if(x%2 == 0) {
            int start = x*x;
            return start - (y-1);
        }
        else {
            int start = ((x-1)*(x-1)) + 1;
            return start + (y-1);
        }
    }
    else {
        if(y&1) {
            int start = y*y;
            return start - (x-1);
        }
        else {
            int start = ((y-1)*(y-1)) + 1;
            return start + (x-1);
        }
    }
}

int32_t main() {

    int t;
    cin >> t;

    int x, y;
    while(t--) {
        cin >> x >> y;
        cout << get(x, y) << "\n";
    }

    return 0;
}