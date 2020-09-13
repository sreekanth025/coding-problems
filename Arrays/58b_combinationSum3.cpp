/*
Find all possible combinations of k numbers that add up to a number n, 
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
*/

// Problem Link: https://leetcode.com/problems/combination-sum-iii/

#include<bits/stdc++.h>
using namespace std; 

// Approach: BackTracking
class Solution {
public:
    int k2; 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9); 
        iota(nums.begin(), nums.end(), 1); 
        
        k2=k;
        vector<vector<int>> result;
        vector<int> temp;
        
        _helper(nums, 0, 0, n, temp, result);
        return result;
    }
    
    void _helper(vector<int>& nums, int start, int sum, int target, vector<int>& temp, vector<vector<int>>& result) {
        
        if(sum > target) return; 
        if(sum==target) {
            if(temp.size()==k2) result.push_back(temp); 
            return;
        }
        
        for(int i=start; i<nums.size(); i++) {
            temp.push_back(nums[i]); 
            _helper(nums, i+1, sum+nums[i], target, temp, result); 
            temp.pop_back();
        }
    }
};