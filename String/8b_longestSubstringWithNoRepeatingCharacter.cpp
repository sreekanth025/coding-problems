/*
Given a string, find the length of the longest substring 
without repeating characters.
*/

// Problem link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int result=0; 
        vector<int> lastIndex(256, -1); 
        
        int i=0; 
        for(int j=0; j<n; j++)
        {
            i = max(i, lastIndex[s[j]]+1); 
            result = max(result, j-i+1); 
            lastIndex[s[j]] = j; 
        }
        
        return result;
    }
};