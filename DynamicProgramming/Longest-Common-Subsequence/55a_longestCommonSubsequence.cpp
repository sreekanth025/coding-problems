/*
Given two strings text1 and text2, return the length of their longest common subsequence.
A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without 
changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). 
A common subsequence of two strings is a subsequence that is common to both strings.
*/

// Problem Link: https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m=text1.size(), n=text2.size(); 
        if(m==0 || n==0) return 0;
        
        vector<vector<int>> dp(m+1, vector<int>(n+1,0)); 
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 || j==0) {
                    dp[i][j]=0; 
                    continue;
                }
                
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        
        return dp[m][n]; 
    }
};
