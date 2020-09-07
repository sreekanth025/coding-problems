/*
Given a positive integer n, break it into the sum of at least two positive integers and 
maximize the product of those integers. Return the maximum product you can get.
*/

// Problem Link: https://leetcode.com/problems/integer-break/

#include<bits/stdc++.h>
using namespace std;  

class Solution {
public:
    int integerBreak(int n) {
        
        if(n <= 2) return 1; 
        
        int dp[n+1]; 
        dp[0]=dp[1]=dp[2] = 1; 
        
        for(int i=3; i<=n; i++) {
            dp[i]=-1; 
            
            for(int k=1; k<=i/2; k++) {
                
                int p = max(i-k, dp[i-k]) * max(k, dp[k]);
                dp[i] = max( dp[i], p); 
            }
        }
        
        return dp[n];
    }
};