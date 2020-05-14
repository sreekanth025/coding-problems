/*
A robot is located at the top-left corner of a m x n grid.
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.
How many possible unique paths are there?
*/

/*
Trivial approach: 
Recursion: count(m,n) = count(m-1, n) + count(m, n-1)
Can be optimized using dynamic programming.
*/

// Time Complexity: O(n^2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int count[m][n]; 
        
        // base cases.
        for(int i=0; i<m; i++) count[i][0] = 1;
        for(int j=0; j<n; j++) count[0][j] = 1; 
        
        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++)
                count[i][j] = count[i-1][j] + count[i][j-1]; 
        return count[m-1][n-1];
    }
};

// Code contains only the required functions. 
/*
Problem link: 
https://leetcode.com/problems/unique-paths/
*/
