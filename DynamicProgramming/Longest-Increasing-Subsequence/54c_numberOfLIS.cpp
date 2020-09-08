/*
Given an unsorted array of integers, find the number of longest increasing subsequence.
*/

// Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size(); 
        if(n<=1) return n; 
        
        vector<int> len(n,1), count(n,1);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i]>nums[j] && len[j]+1 > len[i]) {
                    len[i] = len[j]+1; 
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j] && len[j]+1 == len[i]) {
                    count[i] += count[j]; 
                }
            }
        }
        
        int maxi = -1; 
        for(int x: len) maxi = max(x, maxi); 
        
        int result=0; 
        for(int i=0; i<n; i++) {
            if(len[i]==maxi) result += count[i]; 
        }
        return result; 
    }
};