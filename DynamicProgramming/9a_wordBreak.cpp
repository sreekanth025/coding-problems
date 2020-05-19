/*
Given a non-empty string s and a dictionary wordDict containing a 
list of non-empty words, determine if s can be segmented into a 
space-separated sequence of one or more dictionary words.
*/

// Problem link: https://leetcode.com/problems/word-break/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        if(n == 0) return true; 
        
        bool dp[n+1];
        memset(dp, false, sizeof(dp));
        
        for(int i=1; i<=n; i++)
        {
            if(dp[i] == false && dictContain(s.substr(0, i), wordDict)) dp[i]=true;
            if(dp[i] == true)
            {
                if(i == n) return true;
                for(int j=i+1; j<=n; j++)
                {
                    if(dp[j] == false && dictContain(s.substr(i, j-i), wordDict)) dp[j] = true;
                    if(j == n && dp[j] == true) return true;
                }
            }
        }
        
        return false;
    }
    
    bool dictContain(string word, vector<string>& wordDict)
    {
        for(auto x:wordDict)
            if(x.compare(word) == 0) return true;
        return false;
    }
};