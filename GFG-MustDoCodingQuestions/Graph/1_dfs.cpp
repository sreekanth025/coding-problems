#include<bits/stdc++.h>
using namespace std; 

void _helper(vector<int> g[], int v, vector<int>& result, vector<bool>& vis) {
    
    result.push_back(v); 
    for(int x: g[v]) {
        if(!vis[x]) {
            vis[x] = true; 
            _helper(g, x, result, vis);
        }
    }
}

vector <int> dfs(vector<int> g[], int n)
{
    vector<int> result; 
    vector<bool> vis(n,false); 
    
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            vis[i]=true; 
            _helper(g, i, result, vis);
        }
    }
    
    return result;
}