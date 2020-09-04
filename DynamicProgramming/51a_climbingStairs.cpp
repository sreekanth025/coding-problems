/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

// Problem Link: https://leetcode.com/problems/climbing-stairs/submissions/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int climbStairs(int n) {
        /*
        int dp[n+1]; 
        
        dp[0]=1; 
        dp[1]=1;
        */
        int pre2 = 1; 
        int pre1 = 1; 
        
        int result=1; 
        for(int i=2; i<=n; i++) {
            // dp[i] = dp[i-1]+dp[i-2]; 
             
            result = pre1 + pre2; 
            pre2 = pre1; 
            pre1 = result;
        }
        
        // return dp[n];
        return result;
    } 
};