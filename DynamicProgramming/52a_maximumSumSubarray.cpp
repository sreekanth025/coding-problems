/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has 
the largest sum and return its sum.
*/

// Problem Link: https://leetcode.com/problems/maximum-subarray/

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(); 
        if(n==0) return 0; 
        if(n==1) return nums[0]; 
        
        int neg=true; 
        for(int x: nums) {
            if(x>0) {
                neg=false;
                break; 
            }
        }
        
        if(neg) {
            int result = INT_MIN;
            for(int x: nums) result = max(result, x); 
            return result;
            
        }
        
        vector<int> dp(n+1); 
        dp[0]=0; 
        
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i-1]+nums[i-1];   
        }
        
        int min_ind = 0; 
        int result = -1; 
        
        for(int i=1; i<=n; i++) {
            if(dp[i] < dp[min_ind]) min_ind = i; 
            
            result = max(result, dp[i]-dp[min_ind]);
        }
        
        return result;
    }
};

// kadane's Algo: 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size(); 
        if(n==0) return 0; 
        
        int dp[n]; 
        dp[0]=nums[0];
        for(int i=1; i<n; i++) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]); 
        }
        
        int result = dp[0]; 
        for(int x: dp) result = max(result, x); 
        return result; 
    }
};