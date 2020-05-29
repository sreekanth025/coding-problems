/*
Given a string s, the power of the string is the maximum length of a non-empty substring 
that contains only one unique character. Return the power of the string
*/

// Problem Link: https://leetcode.com/problems/consecutive-characters/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int max = 1; 
        int len = 1; 
        
        for(int i=1; i<n; i++)
            if(s[i] == s[i-1])
            {
                len++; 
                if(len > max) max = len;
            }
            else len = 1;
        
        return max;
    }
};