/*
Given an array of integers nums and an integer limit, return the size of the longest continuous subarray 
such that the absolute difference between any two elements is less than or equal to limit.
In case there is no subarray satisfying the given condition return 0.
*/


#include<bits/stdc++.h>
using namespace std; 


// Method 1: 
// Time Complexity: O(n^2) (exceeds time limit)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int max_len = 0;
        
        for(int i=0; i<n; i++)
        {
            int max_element = nums[i];
            int min_element = nums[i]; 
            
            for(int j=i; j<n; j++)
            {
                if(nums[j] > max_element) max_element = nums[j];
                if(nums[j] < min_element) min_element = nums[j];
                if(max_element-min_element <= limit) max_len = max(max_len, j-i+1);
            }
        }
        
        return max_len;
    }
};


// Method 2:
// Time Complexity: O(n*(lg n))
// multiset stores all the element including repeated element in a sorted order. 
// All operations in Multiset occurs in Log n time

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0, j; 
        multiset<int> m; 
        
        for(j=0; j<nums.size(); j++)
        {
            m.insert(nums[j]);  
            if(*m.rbegin() - *m.begin() > limit) m.erase(m.find(nums[i++]));
        }
        
        return j-i;
    }
};