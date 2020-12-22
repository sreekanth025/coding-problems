// Problem Link: https://codeforces.com/contest/1462/problem/B

#include <bits/stdc++.h>
using namespace std; 
 
string solve() {
 
	int n; 
	cin >> n; 
 
	string s; 
	cin >> s; 
 
	for(int i=0; i<=4; i++) {
 
		string s1 = s.substr(0, i); 
		string s2 = s.substr(n-4+i); 
 
		string s3 = s1+s2;
		if(s3 == "2020") 
			return "YES"; 
	}
 
	return "NO";
}
 
int main() {
 
	// freopen("input.txt", "r", stdin); 
 
	int t;
	cin >> t; 
 
	while(t--) {
		// solve();
		cout << solve() << "\n";
	}
 
	return 0;
}