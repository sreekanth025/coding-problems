/*
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

// Problem Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap; 
        for(auto x: nums) maxHeap.push(x); 
        
        k--; 
        while(k--)
            maxHeap.pop(); 
        return maxHeap.top();
    }
};