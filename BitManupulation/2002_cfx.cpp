// Problem Link: https://codeforces.com/problemset/problem/1438/B

#include <bits/stdc++.h>
using namespace std; 

#define int long long

string solve() {

	int n;
	cin >> n; 

	map<int, int> m; 
	for(int i=0; i<n; i++) {
		int p;
		cin >> p; 
		m[p]++; 
	}

	for(auto it = m.begin(); it != m.end(); it++) {
		if(it->second > 1) 
			return "YES";
	}

	return "NO";
}

int32_t main() {

	// freopen("input.txt", "r", stdin); 

	int t;
	cin >> t; 

	while(t--) {
		// solve();
		cout << solve() << "\n";
	}

	return 0;
}