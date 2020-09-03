/*
Given a directed acyclic graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.
*/

// Problem Link: https://leetcode.com/problems/all-paths-from-source-to-target/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result; 
        
        queue<vector<int>> q; 
        vector<int> source(1,0); 
        int target = graph.size()-1; 
        
        q.push(source); 
        
        while(!q.empty()) {
            vector<int> top = q.front();
            q.pop(); 
            
            if(top.back() == target) {
                result.push_back(top);
                continue; 
            }
            
            // else 
            int s = top.back(); 
            for(int x: graph[s]) {
                top.push_back(x); 
                q.push(top); 
                top.pop_back(); 
            }
        }
        
        return result; 
    } 
};