/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.
Now consider if some obstacles are added to the grids. 
How many unique paths would there be?
*/

// Time Complexity: O(m*n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int count[m][n];
        memset(count, 0, sizeof(count)); 
        
        for(int i=0; i<m; i++)
        {
            if(obstacleGrid[i][0] == 0)
                count[i][0] = 1;
            else break;
        }
        
        for(int j=0; j<n; j++)
        {
            if(obstacleGrid[0][j] == 0)
                count[0][j] = 1;
            else break;
        }
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 0) 
                    count[i][j] = count[i-1][j] + count[i][j-1];
                else count[i][j] = 0;
            }
        
        return count[m-1][n-1];
    }
};

// Code contains only the required functions. 
// Problem link: https://leetcode.com/problems/unique-paths-ii/
