/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
objects of the same color are adjacent, with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

// problem Link: https://leetcode.com/problems/sort-colors/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        nums.push_back(1e9); 
        quick_sort(nums, 0, nums.size()-1); 
        nums.pop_back();
    }

private:
    
    int partition(vector<int>& nums, int low, int high) {
        int p = low; 
        int i=low, j=high;    
        
        while(i<j) {
            do{i++;} while(i<high && nums[i] <= nums[p]); 
            do{j--;} while(j>low && nums[j] > nums[p]); 
            if(i<j) swap(nums[i], nums[j]); 
        }
        
        swap(nums[p], nums[j]); 
        return j;
    }
    
    void quick_sort(vector<int>& nums, int low, int high){
        if(low < high) {
            int p = partition(nums, low, high); 
            quick_sort(nums, low, p); 
            quick_sort(nums, p+1, high);
        }
    } 
};