/*
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different substrings 
even they consist of same characters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); 
        bool dp[n][n];
        memset(dp, false, sizeof(dp)); 
        
        for(int i=0; i<n; i++) {
            dp[i][i] = true; 
        }
        
        for(int i=1; i<n; i++) {
            if(s[i]==s[i-1]) dp[i-1][i] = true;
        }
        
        for(int k=2; k<n; k++) {
            for(int i=0; i<n-k; i++) {
                int j=i+k; 
                dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1]; 
            }
        }
        
        int result=0; 
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(dp[i][j]) result++;
            }
        }
        
        return result;
    }
};