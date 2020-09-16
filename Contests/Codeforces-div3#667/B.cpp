// problem Link: https://codeforces.com/contest/1409/problem/B

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

int solve() {
	int a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;

	int ans = 1e18;
	for(int i=0; i<2; i++) {
		int da = min(n, a-x); 
		int db = min(n-da, b-y); 

		ans = min(ans, (ll)(a-da)*(b-db)); 
		swap(a,b);
		swap(x,y);
	}
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