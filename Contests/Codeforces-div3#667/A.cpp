// Problem Link: https://codeforces.com/contest/1409/problem/A

#include<bits/stdc++.h>
using namespace std;

int solve() {
	int a,b;
	cin >> a >> b; 

	int diff = abs(a-b);
	int ans=diff/10; 
	diff -= (ans*10); 
	if(diff>0) return ans+1; 
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 

	freopen("input.txt", "r", stdin); 
	int tc=1;
	cin>>tc; 
	while (tc--) {
		cout << solve() << "\n";
	}
	
	return 0;
}