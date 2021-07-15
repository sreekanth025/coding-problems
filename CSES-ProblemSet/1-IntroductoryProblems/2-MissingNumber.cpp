#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://cses.fi/problemset/task/1083/

#define int long long

// O(n) time, O(n) extra space
void method_1() {
    
    int n;
    cin >> n;

    int p;
    vector<bool> arr(n, false);
    for(int i=0; i<n-1; i++) {
        cin >> p;
        arr[p-1] = true;
    }

    for(int i=0; i<n; i++) {
        if(!arr[i]) {
            cout << i+1 << "\n";
            return;
        }
    }
}

void method_2() {

    int n;
    cin >> n;

    int sum=0, p;
    for(int i=0; i<n-1; i++) {
        cin >> p;
        sum += p;
    }

    cout << (n*(n+1))/2 - sum << "\n";
}

int32_t main() {
    // method_1();
    method_2();
    return 0;
}