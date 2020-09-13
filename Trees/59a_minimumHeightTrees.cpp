/*
Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges 
where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, 

you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h.
Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.
The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
*/

// Problem Link: https://leetcode.com/problems/minimum-height-trees/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> depth;
    vector<int> parent; 
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        adj.assign(n, vector<int>());
        depth.assign(n, 0); 
        parent.assign(n, -1); 
        
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]); 
            adj[edge[1]].push_back(edge[0]); 
        }
        
        
        _dfsUtil(0, -1, 0); 
        
        
        int max_depth = -1;
        int x;
        
        for(int i=0; i<n; i++) {
            if(depth[i] > max_depth) {
                max_depth = depth[i];
                x = i;
            }
        }
        int start = x; 
        parent[start] = -1; 
        
        _dfsUtil(x, -1, 0);       
        max_depth = -1;
        for(int i=0; i<n; i++) {
            if(depth[i] > max_depth) {
                max_depth = depth[i];
                x = i;
            }
        }
        int finish = x; 
        
        
        vector<int> path; 
        while(finish != start) {
            path.push_back(finish); 
            finish = parent[finish]; 
        } 
        path.push_back(start); 
        
        vector<int> result; 
        int ps = path.size(); 
        if(ps&1) {
            result.push_back(path[ps/2]); 
        }
        else {
            result.push_back(path[ps/2]); 
            result.push_back(path[(ps/2)-1]); 
        }
        
        return result;
    }
    
private: 
    void _dfsUtil(int s, int p, int dep) {
        
        depth[s] = dep;
        parent[s] = p; 
        for(int x: adj[s])
            if(x != p) _dfsUtil(x, s, dep+1);
    }
   
};