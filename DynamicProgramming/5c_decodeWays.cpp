/*
Given a non-empty string containing only digits, 
determine the total number of ways to decode it.
*/

// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(); 
        
        int count[n+1];
        count[0] = 1;
        count[1] = 1;
        
        if(s[0] == '0') return 0;
        for(int i=2; i<=n; i++)
        {
            count[i] = 0;
            if(s[i-1] > '0') count[i] = count[i-1]; 
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7'))
                count[i] += count[i-2]; 
        }
        
        return count[n];
    }
};

// Code contains only the required functions. 
// Problem link: https://leetcode.com/problems/decode-ways/