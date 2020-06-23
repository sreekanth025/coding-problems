/*
Given a collection of distinct integers, return all possible permutations.
*/

// Problem Link: https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

// Using stl function.
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; 
        sort(nums.begin(), nums.end());
        do{
            vector<int> tmp; 
            for(auto x: nums) tmp.push_back(x);  
            result.push_back(tmp);
        } while(next_permutation(nums.begin(), nums.end()));
        
        return result;
    }
};