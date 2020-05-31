/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of 
all these characters a, b and c.
*/

// Problem Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0); 
        int result=0; 
        
        for(int lo=-1, hi=0; hi < s.length(); hi++)
        {
            count[s[hi] - 'a']++; 
            while(count[0]>0 && count[1]>0 && count[2]>0)
            {
                result += s.length()-hi; 
                count[s[++lo] - 'a']--; 
            }
        }
        
        return result;
    }
};