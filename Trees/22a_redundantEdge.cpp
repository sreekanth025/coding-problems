/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), 
with one additional edge added. The added edge has two different vertices chosen from 1 to N, 
and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, 
that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array. 
The answer edge [u, v] should be in the same format, with u < v.
*/

// Problem link: https://leetcode.com/problems/redundant-connection/
// Approach: Union-Find data Structure. 

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2000, 0); 
        for(int i=0; i<p.size(); i++)
            p[i] = i; 
        
        vector<int> result;
        for(auto edge: edges)
        {
            int node1 = edge[0], node2 = edge[1]; 
            while(node1 != p[node1]) node1 = p[node1]; 
            while(node2 != p[node2]) node2 = p[node2]; 
            
            if(node1 == node2) { result=edge; break; }
            else p[node1] = node2;
        }
        return result;
    }
};