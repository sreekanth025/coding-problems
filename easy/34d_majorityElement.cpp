/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊n/2⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array
*/

// Problem Link: https://leetcode.com/problems/majority-element/

#include<bits/stdc++.h>
using namespace std;

// Method 1: 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        return nums[n/2];
    }
};

// Method 2: 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0; 
        int candidate=-1; 
        for(int x: nums)
        {
            if(count==0) candidate=x; 
            count += (x==candidate) ? 1:-1; 
        }
        return candidate;
    }
};