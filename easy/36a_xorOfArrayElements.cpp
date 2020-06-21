/*
Given an integer n and an integer start.
Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.
Return the bitwise XOR of all elements of nums.
*/

// Problem Link: https://leetcode.com/contest/weekly-contest-194/problems/xor-operation-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int result=0; 
        for(int i=0; i<n; i++)
            result ^= (2*i+start); 
        return result;
    }
};