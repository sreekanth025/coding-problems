/*
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
*/

// Problem Link: https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end()); 
        for(int i=0; i<matrix.size(); i++) {
            for(int j=i+1; j<matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]); 
            }
        }
    }
};

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/


/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/