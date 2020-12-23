// Problem Link: https://codeforces.com/problemset/problem/1405/B

#include <bits/stdc++.h>
using namespace std; 

#define int long long

void solve() {

	int n; 
	cin >> n;

	int psum=0;
	for(int i=0; i<n; i++) {
		int x; 
		cin >> x; 

		if(x > 0) {
			psum += x;
		}
		else if(x < 0) {
			psum = max(psum+x, (int)0); 
		}
	}	

	cout << psum << "\n";
}

int32_t main() {

	// freopen("input.txt", "r", stdin); 

	int t;
	cin >> t; 

	while(t--) {
		solve();
		// cout << solve() << "\n";
	}

	return 0;
}