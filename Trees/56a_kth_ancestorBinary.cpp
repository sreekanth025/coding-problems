/*
You are given a tree with n nodes numbered from 0 to n-1 in the form of a 
parent array where parent[i] is the parent of node i. The root of the tree is node 0.
Implement the function getKthAncestor(int node, int k) to return the k-th ancestor of the given node. 
If there is no such ancestor, return -1.
The k-th ancestor of a tree node is the k-th node in the path from that node to the root.
*/

// Problem Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

#include<bits/stdc++.h>
using namespace std; 

class TreeAncestor {
public:
    vector<vector<int>> dp; 
    TreeAncestor(int n, vector<int>& parent) {
        
        // ceil [log(1e6)/log(2)] = 20. 
        dp.assign(n, vector<int>(20));
        for(int i=0; i<n; i++) dp[i][0] = parent[i]; 
        for(int i=0; i<n; i++) {
            for(int j=1; j<20; j++) {
                if(dp[i][j-1]==-1) dp[i][j] = -1; 
                else dp[i][j]  = dp[dp[i][j-1]][j-1]; 
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0; i<20; i++) {
            if((k>>i) & 1) node = dp[node][i];
            if(node == -1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */