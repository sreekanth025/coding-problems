#include<bits/stdc++.h>
using namespace std;
#define int long long

list<int>::iterator circular_next(list<int>& lis, list<int>::iterator it) {
    return (next(it) == lis.end()) ? lis.begin() : ++it;
}

int32_t main() {

    int n;
    cin >> n;

    list<int> lis;
    for(int i=1; i<=n; i++) lis.push_back(i);

    auto start = lis.begin();
    while(!lis.empty()) {
        auto del = circular_next(lis, start);
        start = circular_next(lis, del);
        cout << *del << " ";
        lis.erase(del);
    }

    cout << "\n";
    return 0;
}