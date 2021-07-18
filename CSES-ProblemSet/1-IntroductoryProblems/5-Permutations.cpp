#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://cses.fi/problemset/task/1070

#define int long long

void method_1(int n) {

    if(n==1) {
        cout << "1\n";
        return;
    }

    if(n<=3) {
        cout << "NO SOLUTION\n";
        return;
    }

    if(n == 4) {
        cout << "3 1 4 2\n";
        return;
    } 

    int set_1 = 1;
    int set_2 = 2;

    while(set_1 <= n) {
        cout << set_1 << " ";
        set_1 += 2;
    }

    while (set_2 <= n) {
        cout << set_2 << " ";
        set_2 += 2;
    }
    
}

int32_t main() {

    int n;
    cin >> n;

    method_1(n);
    return 0;
}