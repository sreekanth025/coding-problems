/*
Given two arrays nums1 and nums2. Return the maximum dot product between 
non-empty subsequences of nums1 and nums2 with the same length.
A subsequence of a array is a new array which is formed from the original array 
by deleting some (can be none) of the characters without disturbing the 
relative positions of the remaining characters. 
(ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).
*/

// Problem Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
// Time Complexity: O(m*n)

// Approach: DP

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        int INF = 1e8;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -INF));
        
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                dp[i][j] = max({nums1[i-1]*nums2[j-1], dp[i-1][j-1]+nums1[i-1]*nums2[j-1], dp[i-1][j], dp[i][j-1]});
        
        return dp[n][m];
    }
};