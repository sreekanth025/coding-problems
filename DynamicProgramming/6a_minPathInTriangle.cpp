/*
Given a triangle, find the minimum path sum from top to bottom. 
Each step you may move to adjacent numbers on the row below.
*/

// Problem link: https://leetcode.com/problems/triangle/
// Time Complexity: O(n^2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n];
        
        for(int i=0; i<triangle[n-1].size(); i++)
            dp[i] = triangle[n-1][i]; 
        
        for(int i=n-2; i>=0; i--)
            for(int j=0; j<triangle[i].size(); j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        
        return dp[0];
    }
};
