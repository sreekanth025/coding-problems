/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.
*/

// Problem link: https://leetcode.com/problems/maximal-square/
// Time Complexity: O(n^2)

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        
        int columns = matrix[0].size();
        
        bool check = false;
        int sum[rows][columns];
        
        for(int i=0; i<rows; i++)
        {
            sum[i][0] = matrix[i][0]-'0';
            if(matrix[i][0] == '1') check=true;
        }
        for(int j=0; j<columns; j++)
        {
            sum[0][j] = matrix[0][j]-'0'; 
            if(matrix[0][j] == '1') check=true;
        }
        
        int res; 
        if(check) res=1; else res=0;
        
        for(int i=1; i<rows; i++)
            for(int j=1; j<columns; j++)
            {
                if(matrix[i][j] == '1') 
                    sum[i][j] = min(sum[i][j-1], min(sum[i-1][j], sum[i-1][j-1]))+1; 
                else sum[i][j] = 0;
                
                if(sum[i][j] > res) res = sum[i][j];
            }
        
        return res*res;
    }
};