/*
- On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
- Once you pay the cost, you can either climb one or two steps. 
- You need to find minimum cost to reach the top of the floor, and you can either 
  start from the step with index 0, or the step with index 1.
*/

// Problem Link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        
        int dp[n]; 
        dp[0] = cost[0]; 
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]); 
        }
        
        return min(dp[n-1], dp[n-2]);
    }
};

// Space optimized solution: 
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        
        int p2 = cost[0]; 
        int p1 = cost[1]; 
        int k; 
        
        for(int i=2; i<n; i++) {            
            k = cost[i] + min(p1, p2); 
            p2 = p1; 
            p1 = k; 
        }
        
        return min(p1, p2);
    }
};