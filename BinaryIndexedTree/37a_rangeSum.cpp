/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
*/

// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/

#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> BIT;
    NumArray(vector<int>& nums) {
        BIT.assign(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++)
            update(i, nums[i]); 
    }
    
    void update(int i, int val) {
        val = val - _sum(i)+_sum(i-1); 
        i++; 
        while(i < BIT.size())
        {
            BIT[i] += val; 
            i = _next(i);
        }
    }
    
    int sumRange(int i, int j) {
        return _sum(j) - _sum(i-1);
    }
    
private: 
    int _parent(int x) { return x - (x & -x); }
    int _next(int x) { return x + (x & -x); }
    int _sum(int i) {
        i++; 
        int sum=0; 
        while(i>0)
        {
            sum += BIT[i];
            i = _parent(i); 
        }
        
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */