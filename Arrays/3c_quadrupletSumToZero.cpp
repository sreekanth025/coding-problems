/*
Given an array nums of n integers and an integer target, 
are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
*/

// O(n^3) - Time Complexity: 

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> result; 
        
        for(int i=0; i<n-3; i++)
        {
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            for(int j=i+1; j<n-2; j++)
            {
                if(j != i+1 && nums[j] == nums[j-1]) continue; 
                
                int left = j+1; 
                int right = n-1;
                
                int x = nums[i] + nums[j]; 
                while(left < right)
                {
                    int sum = x + nums[left] + nums[right];
                    
                    if(sum == target)
                    {
                        vector<int> temp(4); 
                        temp[0]=nums[i]; temp[1]=nums[j];
                        temp[2]=nums[left]; temp[3]=nums[right];
                        
                        result.push_back(temp); 
                        left++;
                        right--; 
                        
                        while(left<right && nums[left] == nums[left-1]) left++;
                        while(left<right && nums[right] == nums[right+1]) right--;
                    }
                    else if(sum < target) left++;
                    else right--;
                }
            }
        }
        
        return result;
    }
};

// code contains only the required function. 
/*
Problem Link: 
https://leetcode.com/problems/4sum/
*/
