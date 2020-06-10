/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
*/

// Problem link: https://leetcode.com/problems/search-insert-position/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0; 
        
        int low = 0, high = nums.size()-1;
        while(low <= high)
        {
            int mid = low + (high-low)/2; 
            if(nums[mid] < target) low = mid+1; 
            else high = mid-1;
        }
        return low;
    }
};