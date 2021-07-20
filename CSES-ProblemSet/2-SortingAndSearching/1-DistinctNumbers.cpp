#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://cses.fi/problemset/task/1621

#define int long long

void method_1() {

    int n;
    cin >> n;

    set<int> s;
    int p;
    for(int i=0; i<n; i++) {
        cin >> p;
        s.insert(p);
    }

    cout << s.size() << "\n";
}

int32_t main() {
    method_1();
}