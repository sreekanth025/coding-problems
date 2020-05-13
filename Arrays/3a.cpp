/*
Given an array nums of n integers, 
are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
*/

// O(n^2) - Time Complexity: 

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> output; 
        
        sort(nums.begin(), nums.end()); 
        for(int i=0; i<n-1; i++)
        {
            int left = i+1; 
            int right = n-1; 
            int x = nums[i]; 
                        
            while(left < right)
            {
                if(x+nums[left]+nums[right] == 0)
                {
                    vector<int> temp(3);
                    temp[0] = x; temp[1]=nums[left]; temp[2]=nums[right]; 
                    output.insert(temp);
                    
                    left++;
                    right--; 
                }
                
                else if(x+nums[left]+nums[right] < 0) left++;
                else right--;
            }
        }
        
        vector<vector<int>> ans;
        
        for(auto it = output.begin(); it!=output.end(); it++)
            ans.push_back(*it);
        return ans;
    }
};

// code contains only the required function. 
/*
Problem Link: 
https://leetcode.com/problems/3sum/
*/