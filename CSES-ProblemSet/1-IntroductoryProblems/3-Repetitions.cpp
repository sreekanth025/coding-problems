#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://cses.fi/problemset/task/1069/

#define int long long

// O(n)
void method_1(string str) {

    int ans=1;

    int count=1;
    for(int i=1; i<str.size(); i++) {
        if(str[i] == str[i-1]) {
            count++;
            ans = max(ans, count);
        } else {
            count=1;
        }
    }

    cout << ans << "\n";
}

int32_t main() {

    string str;
    cin >> str;

    method_1(str);
}