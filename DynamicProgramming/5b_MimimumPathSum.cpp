/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right 
which minimizes the sum of all numbers along its path.
Print the minimum sum.
*/

// Time Complexity: O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        
        int min_sum[m][n]; 
        
        for(int i=0; i<m; i++)
        {
            if(i == 0) min_sum[i][0] = grid[0][0]; 
            else min_sum[i][0] = min_sum[i-1][0] + grid[i][0]; 
        }
        
        for(int j=1; j<n; j++)
            min_sum[0][j] = min_sum[0][j-1] + grid[0][j];
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                int m = min(min_sum[i-1][j], min_sum[i][j-1]);
                min_sum[i][j] = m + grid[i][j]; 
            }
        
        return min_sum[m-1][n-1];
    }
};

// Code contains only the required functions. 
// Problem link: https://leetcode.com/problems/minimum-path-sum/submissions/