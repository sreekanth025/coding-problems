/*
Given the array of integers nums, you will choose two different indices i and j 
of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/

// Problem Link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a = (nums[0]-1)*(nums[1]-1);
        int b = (nums[n-1]-1)*(nums[n-2]-1);
        
        return max(a, b);
    }
};