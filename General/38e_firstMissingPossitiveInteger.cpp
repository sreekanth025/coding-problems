/*
Given an unsorted integer array, find the smallest missing positive integer.
*/

// Problem Link: https://leetcode.com/problems/first-missing-positive/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> count; 
        for(int x: nums) count[x]++; 
        
        int result;
        int i=1; 
        while(true)
        {
            if(count[i]==0){ result=i; break; }
            i++;
        }
        
        return result;
    }
};