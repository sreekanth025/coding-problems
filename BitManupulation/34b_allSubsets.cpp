/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
*/

// Problem Link: https://leetcode.com/problems/subsets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(); 
        int total = pow(2, n); 
        
        vector<vector<int>> result(total, vector<int>()); 
        for(int i=0; i<n; i++)
            for(int j=0; j<total; j++)
                if((j>>i)&1) result[j].push_back(nums[i]); 
        return result; 
    }
};