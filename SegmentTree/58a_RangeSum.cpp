/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
*/

// Problem Link: https://leetcode.com/problems/range-sum-query-mutable/

#include<bits/stdc++.h>
using namespace std; 

class NumArray {
public:
    vector<int> segtree; 
    int N;
    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        N=n;
        if(N==0) 
            return;
        
        n = pow2(n);     
        while(nums.size() < n) nums.push_back(0); 
        
        segtree.assign(2*n,0); 
        for(int i=0; i<N; i++) {
            update(i, nums[i]);
        }
        
    }
    
    void update(int i, int val) {
        
        if(N==0) return;
        
        int add = val-(sumRange(0, i)-sumRange(0,i-1));
        
        i += N;
        segtree[i] += add;
        for(i/=2; i>=1; i/=2) segtree[i] = segtree[2*i]+segtree[2*i+1];
        
    }
    
    int sumRange(int i, int j) {
        
        if(N==0) return 0;
        
        if(j<0) return 0;
        
        i+=N; j+=N;
        int s=0;
        
        while(i<=j) {
            if(i%2 == 1) s += segtree[i++];
            if(j%2 == 0) s += segtree[j--];
            
            i/=2;
            j/=2;
        }
        
        return s;
    }

private: 
    
    int pow2(int n) {
        int p = ceil(log2(n)); 
        return pow(2, p);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */