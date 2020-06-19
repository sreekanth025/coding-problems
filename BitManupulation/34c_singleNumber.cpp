/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/

// Problem Link: https://leetcode.com/problems/single-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;  
        for(int x: nums) 
            result ^= x;
        return result;
    }
};

/*
a XOR b XOR a = (a XOR a) XOR b = 0 XOR b = b
*/