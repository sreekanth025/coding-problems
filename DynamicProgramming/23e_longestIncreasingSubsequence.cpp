/*
Given an unsorted array of integers, find the length of longest increasing subsequence.
*/

// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0; 
        int n = nums.size();
        
        int dp[n];
        dp[0] = 1;
        
        int result = 1;
        for(int i=1; i<n; i++)
        {
            int max_value = 0; 
            for(int j=0; j<i; j++)
                if(nums[i] > nums[j])
                    max_value = max(max_value, dp[j]);
            dp[i] = max_value + 1; 
            result = max(result, dp[i]);
        }
        return result; 
    }
};