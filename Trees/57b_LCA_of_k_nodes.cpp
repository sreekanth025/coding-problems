/* 
Problem Link: 
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/tree-queries-21/
*/

#include<bits/stdc++.h>
using namespace std;

// 1 is the root. 
vector<int> parent; 
vector<vector<int>> dp;
vector<int> level;

void get_level(int node) {

	if(node==-1) {
		cout << "some error occuured\n"; 
		return; 
	}

	if(level[node] != -1) return ; 
	if(level[parent[node]] == -1) get_level(parent[node]); 

	level[node] = 1 + level[parent[node]];
}

void preprocess(int n) {

	level[1]=0;
	for(int i=2; i<=n; i++) {
		get_level(i); 
	} 

	for(int i=1; i<=n; i++) {
		for(int j=0; j<20; j++) {
			if(j==0) dp[i][j] = parent[i]; 
			else if(dp[i][j-1] == -1) dp[i][j]=-1; 
			else dp[i][j] = dp[dp[i][j-1]][j-1]; 
		}
	}
}

int kth_ancestor(int node, int k) {

	for(int i=0; i<20; i++) {
		if((k>>i)&1) node = dp[node][i];
		if(node==-1) return -1; 
	}

	return node; 
}

int lca(int a, int b) {

	if(a==b) return a; 
	if(level[a] < level[b]) swap(a,b); 

	a = kth_ancestor(a, level[a]-level[b]); 
	if(a==b) return a; 

	for(int i=19; i>=0; i--) {
		if(dp[a][i] != dp[b][i]) {
			a = dp[a][i]; 
			b = dp[b][i];
		}
	}

	return dp[a][0]; 
}

void solve() {
	int n, q; 
	cin >> n >> q; 

	parent.assign(n+1, -1);
	level.assign(n+1, -1); 
	dp.assign(n+1, vector<int>(20, -1)); 

	for(int i=1; i<=n-1; i++) {
		int p; 
		cin >> p; 
		parent[i+1] = p; 
	}

	preprocess(n); 

	while(q--) {
		int k; 
		cin >> k; 

		vector<int> nodes(k);
		for(int i=0; i<k; i++) cin >> nodes[i]; 

		if(k==1) {
			cout << nodes[0] << "\n"; 
			continue;
		} 

		int ans = lca(nodes[0], nodes[1]); 
		for(int i=2; i<k; i++) {
			ans = lca(ans, nodes[i]); 
		}

		cout << ans << "\n"; 
	}
}

int main() {

	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 

	int test_cases=1; 
	// cin>>test_cases; 
	while(test_cases--) {
		solve(); 
	}

	return 0; 
}