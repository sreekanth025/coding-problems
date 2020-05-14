/*
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.
*/

// O(n^2) - Time Complexity: 

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        int c_sum = INT_MAX;
        
        for(int i=0; i<n-2; i++)
        {
            int left = i+1;  
            int right = n-1; 
            
            int x = nums[i];
            while(left < right)
            {
                int sum = x+nums[left]+nums[right]; 
                if(abs(1LL*target-sum) < abs(1LL*target-c_sum)) c_sum=sum; 
                
                if(sum > target) right--;
                else left++; 
            }
        }
        
        return c_sum;
    }
};

// code contains only the required function. 
/*
Problem Link: 
https://leetcode.com/problems/3sum-closest/
*/
