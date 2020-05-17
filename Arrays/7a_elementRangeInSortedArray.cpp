/*
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.
*/

// Time complexity: O(lg n)
// Problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int end = nums.size()-1;
        
        int mid; 
        int first = -1; 
        
        while(start <= end)
        {
            mid = (start+end)/2; 
            if(nums[mid] == target)
            {
                first = mid;
                break;
            }
            
            if(target < nums[mid])
                end = mid-1; 
            else start = mid+1; 
        }
        
        vector<int> p(2);
        if(first != -1)
        {
            for(start=first; start>0 && nums[start-1]==target; start-- );
            for(end=first; end<nums.size()-1 &&  nums[end+1]==target; end++); 
            
            p[0] = start; 
            p[1] = end;
            return p;
        }
        
        p[0] = -1;
        p[1] = -1;
        return p;
    }
};