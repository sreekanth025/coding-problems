#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve() {

    string s;
    cin >> s;

    int current = 1, ans = 1;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == s[i-1]) ans = max(ans, ++current);
        else current = 1;
    }
    return ans;
}

int32_t main() {
    cout << solve() << "\n";
    return 0;
}