/*
You are given n pairs of numbers. 
In every pair, the first number is always smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. 
Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. 
You needn't use up all the given pairs. You can select pairs in any order.
*/

// Problem Link: https://leetcode.com/problems/maximum-length-of-pair-chain/

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(); 
        if(n<=1) return n; 
        
        vector<int> dp(n,1); 
        sort(pairs.begin(), pairs.end()); 
        int result=1; 
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if((pairs[j][1] < pairs[i][0]) && dp[j]+1 > dp[i]) 
                    dp[i] = dp[j]+1; 
            }
            result = max(result, dp[i]);  
        }
        
        return result; 
    }
};