/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) 
and lower right corner (row2, col2).
*/

// Problem Link: https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/

#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> presum; 
    NumMatrix(vector<vector<int>>& matrix) {
        presum = matrix; 
        
        if(matrix.size()==0 || matrix[0].size()==0) return;
        
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        
        
        for(int i=0; i<n; i++) {
            for(int j=1; j<m; j++) {
                presum[i][j] += presum[i][j-1]; 
            }
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<m; j++) {
                presum[i][j] += presum[i-1][j]; 
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        
        if(presum.size()==0 || presum[0].size()==0) return 0;
        
        if(r1==0) {
            if(c1==0) return presum[r2][c2]; 
            else return presum[r2][c2]-presum[r2][c1-1]; 
        }
        
        if(c1==0) {
            if(r1==0) return presum[r2][c2];
            else return presum[r2][c2] - presum[r1-1][c2]; 
        }
        
        return presum[r2][c2] - presum[r1-1][c2] - presum[r2][c1-1] + presum[r1-1][c1-1]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */