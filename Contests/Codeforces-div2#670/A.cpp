// Problem Link: https://codeforces.com/contest/1406/problem/A

#include<bits/stdc++.h>
using namespace std; 

int solve() {
    int n; 
    cin >> n;

    int count[101];
    memset(count, 0, sizeof(count));   

    int p;
    for(int i=0; i<n; i++) {
        cin >> p;
        count[p]++;
    }

    bool one = false;
    int a=0; 
    for(int i=0; i<100; i++) {

        if(count[i] >= 2) continue; 
        if(!one && !count[i]) return 2*i;
        if(one && !count[i]) return a+i;

        if(!one && count[i]==1) {
            a=i; 
            one=true;
            continue;
        }
    }

    if(one) return a+100; 
    return 2*100;
}

int32_t main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    freopen("input.txt", "r", stdin);

    int test_cases=1;
    cin>>test_cases; 
    while ((test_cases--)) {
        cout << solve() << "\n";
    }
    return 0;
}