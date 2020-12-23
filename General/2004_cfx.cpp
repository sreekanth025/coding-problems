// problem link: https://codeforces.com/problemset/problem/1277/A

#include <bits/stdc++.h>
using namespace std; 

#define int long long

void solve() {

	int n; 
	cin >> n;

	int p = n;
	int d0, digits = 0;

	while(p) {
		digits++;
		d0 = p%10;
		p/=10;
	}

	int ans = (digits-1)*9 + (d0-1);

	char c = '0'+d0; 
	string str = ""; 
	for(int i=0; i<digits; i++)
		str += c; 

	int x = stoll(str);

	ans += (x<=n) ? 1:0;
	cout << ans << "\n";
	
	// cout << digits << " " << d0 << " " << str << "\n\n";
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