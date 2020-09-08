/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one 
envelope is greater than the width and height of the other envelope.
What is the maximum number of envelopes can you Russian doll? (put one inside other)
*/

// Problem Link: https://leetcode.com/problems/russian-doll-envelopes/

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size(); 
        if(n==0 || n==1) return n; 
        
        sort(envelopes.begin(), envelopes.end());
        int result = 1; 
        
        vector<int> dp(n,1); 
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if((envelopes[i][0] > envelopes[j][0]) && 
                   (envelopes[i][1] > envelopes[j][1]) && 
                   (dp[j]+1 > dp[i])) {
                    
                    dp[i]=dp[j]+1; 
                }
                
            }
            
            result = max(result, dp[i]); 
        }
        
        return result;
    }
};