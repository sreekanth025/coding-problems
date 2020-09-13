/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the
manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. 
All points are connected if there is exactly one simple path between any two points.
*/

// Problem Link: https://leetcode.com/problems/min-cost-to-connect-all-points/

#include<bits/stdc++.h> 
using namespace std; 

// Approach: minimum spanning tree (Prims Algo)
// Time Limit Exceeded (67/72 test cases passed). 
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();  
        int ans=0; 
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                q.push({ 
                    abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), 
                    i, 
                    j
                    });
            }
        }
        
        vector<int> par(n); 
        iota(par.begin(), par.end(), 0); 
        int count=0; 
        
        while(!q.empty() && count < n) {
            
            vector<int> t = q.top();
            int dis = t[0], i=t[1], j=t[2]; 
            q.pop();
            pair<int, int> a =_find(par, i), b=_find(par, j); 
            
            i=a.first, j=b.first;
            int hi=a.second, hj=b.second;
            
            if(i != j) {
                ans += dis;
                count++; 
                
                if(hi > hj) par[j] = i;
                else par[i]=j; 
            }
        }
        
        return ans;
    }
    
private: 
    pair<int, int> _find(vector<int>& par, int i) {
        int h=0;
        while(i != par[i]) {
            i = par[i]; 
            h++; 
        }
        return {i,h};
    }
};