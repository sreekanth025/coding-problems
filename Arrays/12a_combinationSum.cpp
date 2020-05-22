/*
Given a set of candidate numbers (candidates) (without duplicates) 
and a target number (target), find all unique combinations in 
candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates 
unlimited number of times.
*/

// Problem link: https://leetcode.com/problems/combination-sum/
// Approach: BackTracking

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result; 
        vector<int> temp; 
        helper(candidates, 0, target, 0, temp, result);
        return result;
    }
    
    void helper(vector<int>& candidates, int start, int target, int sum, vector<int>& temp, vector<vector<int> >& result) {
        
        if(sum > target) return;
        if(sum == target)
        {
            result.push_back(temp);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            helper(candidates, i, target, sum+candidates[i], temp, result);
            temp.pop_back();
        }
    }
};