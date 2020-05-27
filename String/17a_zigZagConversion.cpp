/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
    P   A   H   N
    A P L S I I G
    Y   I   R
And then read line by line: "PAHNAPLSIIGYIR".
Write the code that will take a string and make this conversion given a number of rows.
*/

// Problem Link: https://leetcode.com/problems/zigzag-conversion/
// Time Complexity: O(n) 
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size(); 
        if(numRows == 1) return s; 
        
        vector<string> rows(numRows, "");
        
        int current_row = 0;
        bool increase_row = true; 
        
        for(int i=0; i<n; i++)
        {
            if(increase_row)
            {
                rows[current_row].push_back(s[i]); 
                current_row++;
                if(current_row == numRows) 
                {
                    increase_row = false;
                    current_row -= 2; 
                }
            }
            else
            {
                rows[current_row].push_back(s[i]);  
                current_row--;
                if(current_row == -1)
                {
                    increase_row = true;
                    current_row = 1; 
                }
            }
        }
        
        string output = "";
        for(auto x:rows)
            output += x;
        return output;
    }
};