// Problem Link: https://codeforces.com/problemset/problem/1251/A

#include <bits/stdc++.h>
using namespace std; 

#define int long long

string _helper(string str, int start) {

	int n = str.size();
	string s = ""; 

	char c = str[start];
	s = s + c; 

	for(int i=start+1; i<n; i++) {
		if(str[i]==c) {
			s = s + c; 
		}
		else {
			return s;
		}
	}

	return s;
}

void solve() {
	
	string str; 
	cin >> str; 

	int n = str.size(); 
	set<char> ans;   

	for(int i=0; i<n; i++) {

		string same = _helper(str, i);
		char c = same[0]; 
		i += (same.size()-1);

		// cout << c << " len: " << same.size() << "\n";

		if(same.size() & 1) {
			ans.insert(c);
		}
	}

	for(auto x: ans) {
		cout << x;
	}
	cout << "\n";
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