/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
*/

// Time Complexity: O(lg n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int pivot = findPivot(nums, 0, n-1);
        
        if(pivot == -1) return binarySearch(nums, 0, n-1, target);
        if(nums[pivot] == target) return pivot; 
        
        int p = binarySearch(nums, 0, pivot-1, target);
        int q = binarySearch(nums, pivot+1, n-1, target); 
        
        int result = p>q ? p:q;
        return result;
    }
    
    int findPivot(vector<int>& nums, int low, int high)
    {
        if(high < low) return -1;
        if(high == low) return low; 
        
        int mid = (low+high)/2;
        
        if(mid < high && nums[mid] > nums[mid+1]) return mid; 
        if(mid > low && nums[mid] < nums[mid-1]) return (mid-1);  
        
        if(nums[mid] <= nums[low]) return findPivot(nums, low, mid-1);
        return findPivot(nums, mid+1, high);
    }
    
    int binarySearch(vector<int>& nums, int low, int high, int target)
    {
        if(high < low) return -1; 
        
        int mid = (low+high)/2;
        if(target == nums[mid]) return mid; 
        
        if(target > nums[mid])  return binarySearch(nums, mid+1, high, target);
        else return binarySearch(nums, low, mid-1, target);
    }
};

// Code contains only the required functions. 
/*
Problem link: 
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
