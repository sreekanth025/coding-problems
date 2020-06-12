/*
Given an array of non-negative integers, 
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps
*/

// Problem link: https://leetcode.com/problems/jump-game-ii/
// Approach: BFS

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int steps=1, i, curEnd=0, newEnd=0, n=nums.size(); 
        if(n<=1) return 0; 
        
        for(int i=0; i<=curEnd; i++)
        {
            newEnd = max(newEnd, i+nums[i]); 
            if(newEnd >= n-1) return steps; 
            if(i==curEnd) { steps++; curEnd=newEnd; }
        }
        return INT_MAX;
    }
};