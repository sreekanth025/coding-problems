/*
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
*/

// Problem link: https://leetcode.com/problems/shuffle-the-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result; 
        for(int i=0; i<n; i++)
        {
            result.push_back(nums[i]); 
            result.push_back(nums[i+n]);
        }
        return result;
    }
};