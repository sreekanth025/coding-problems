/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.
*/

// Problem Link: https://leetcode.com/problems/largest-divisible-subset/

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size(); 
        if(n==0) return vector<int>(0); 
        
        sort(nums.begin(), nums.end()); 
        
        vector<int> dp(n,1);
        
        int parent[n]; 
        for(int i=0; i<n; i++) parent[i]=i; 
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                if((nums[i]%nums[j]==0) && (dp[j]+1 > dp[i])) {
                    parent[i]=j; 
                    dp[i] = dp[j]+1;
                }
            }
        }
        
        int last_index = 0;
        int maxi = dp[0]; 
        for(int i=1; i<n; i++) {
            if(dp[i] > maxi) {
                maxi = dp[i]; 
                last_index=i; 
            }
        }
        
        vector<int> result;
        int x = last_index; 
        while(x != parent[x]) {
            result.push_back(nums[x]); 
            x = parent[x]; 
        }
        
        result.push_back(nums[x]);
        return result;
    }
};