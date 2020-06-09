/*
Given an array of non-negative integers, 
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
*/

// Problem link: https://leetcode.com/problems/jump-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1; 
        int n = nums.size(); 
        for(int i=n-1; i>=0; i--)
            if(i + nums[i] >= target) target=i;
        
        if(target == 0) return true; 
        return false;
    }
};