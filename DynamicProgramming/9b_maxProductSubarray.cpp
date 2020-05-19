/*
Given an integer array nums, find the contiguous subarray within an 
array (containing at least one number) which has the largest product.
*/

// Problem link: https://leetcode.com/problems/maximum-product-subarray/
// Time complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(); 
        int max_product[n], min_product[n];
        
        max_product[0] = min_product[0] = nums[0]; 
        int result = nums[0];
        
        for(int i=1; i<n; i++)
        {
            if(nums[i] > 0) {
                max_product[i] = max(nums[i], max_product[i-1]*nums[i]);
                min_product[i] = min(nums[i], min_product[i-1]*nums[i]); 
            } else {
                max_product[i] = max(nums[i], min_product[i-1]*nums[i]);
                min_product[i] = min(nums[i], max_product[i-1]*nums[i]);
            }
            
            result = max(result, max_product[i]);
        }
        
        return result;
    }
};