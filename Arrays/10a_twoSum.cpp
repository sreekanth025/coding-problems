/*
Given an array of integers, return indices of the two numbers 
such that they add up to a specific target. You may assume that 
each input would have exactly one solution, 
and you may not use the same element twice.
*/

// Time Complexity: O(lg n)

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> index; 
        for(int i=0; i<n; i++) index[nums[i]].push_back(i); 
        
        sort(nums.begin(), nums.end()); 
        int left = 0,  right = n-1; 
        vector<int> result(2, -1); 
        
        while(left < right)
        {
            int sum = nums[left]+nums[right]; 
            
            if(sum == target)
            {
                result[0] = index[nums[left]].back();
                index[nums[left]].pop_back();
                result[1] = index[nums[right]].back(); 
                index[nums[right]].pop_back(); 
                break;
            }
            
            if(sum < target) left++;
            else right--;
        }
        
        return result; 
    }
};