/*
Given a string s, find the longest palindromic substring in s. 
You may assume that the maximum length of s is 1000.
*/

// Time Complexity: O(n^2).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";
        
        // table[i][j] says whether s[i]...s[j] is a  palindromic substring or not. 
        bool table[n][n];
        memset(table, false, sizeof(table)); 
        
        // Each character is a palindromic substring. (Base case_1 for DP)
        int max_length = 1;
        for(int i=0; i<n; i++) table[i][i] = true; 
        
        // Check for palindromic substrings of length 2.
        int start_index = 0; 
        
        for(int i=0; i<n-1; i++)
            if(s[i] == s[i+1])
            {
                table[i][i+1] = true;
                max_length = 2;
                start_index = i;
            }
        
        // table[i][j] = table[i+1][j-1] & s[i]==s[j] 
        // k = length of substring.
        for (int k=3; k<=n; k++)
        {
            // i = starting index of substring
            for(int i=0; i<n-k+1; i++)
            {
                // let j be the ending index of substring
                int j = i+k-1;
                
                if(table[i+1][j-1] && s[i]==s[j])
                {
                    table[i][j] = true;  
                    
                    if(k > max_length)
                    {
                        max_length = k;
                        start_index = i;
                    }
                }
            }
        }
        
        string out = "";
        for(int i=start_index; i<(start_index+max_length); i++)
            out.push_back(s[i]);
        return out;
    }
};

// Code contains only the required functions. 
/*
Problem link: 
https://leetcode.com/problems/longest-palindromic-substring/
*/
