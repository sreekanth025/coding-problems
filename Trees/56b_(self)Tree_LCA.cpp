// Find LCA of two nodes in a tree; 

#include<bits/stdc++.h> 
using namespace std; 

#define N 100

vector<int> level(N), parent(N); 
vector<vector<int>> dp(N, vector<int>(20, -1)); 
vector<int> adj[N]; 

void dfs(int u, int p){
    parent[u] = p;  
    level[u] = level[p]+1;
    dp[u][0]= p;

    for(int x: adj[u]){
        if(x != p)  dfs(x, u); 
    }
}

void preprocess() {
    for(int i=0; i<N; i++) {
        for(int j=1; j<20; j++) {
            if(dp[i][j-1]==-1) dp[i][j] = -1;
            else dp[i][j] = dp[dp[i][j-1]][j-1]; 
        }
    }
}

int kth_ancestor(int node, int k) {
    for(int i=0; i<20; i++) {
        if((k>>i)&1) node = dp[node][i];
        if(node == -1) return -1; 
    }
    return node; 
}

int lca(int a, int b) {
    if(level[a] < level[b]) swap(a, b); 

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