/*
Implement next permutation, which rearranges numbers into the 
lexicographically next greater permutation of numbers.
If such arrangement is not possible, 
it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
*/

// O(n) - Time Complexity: 

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(); 
        
        int i=n-2; 
        while(i >= 0 && nums[i] >= nums[i+1]) i--; 
        
        if(i>=0)
        {
            int j = n-1; 
            
            // find first element from last that is greater than nums[i].
            while(j>=0 && nums[j] <= nums[i]) j--; 
            
            swap(nums[i], nums[j]);
            reverse(nums.begin()+i+1, nums.end());
        }
        else reverse(nums.begin(), nums.end());
    }
};

// code contains only the required function. 
/*
Problem Link: 
https://leetcode.com/problems/next-permutation/
*/