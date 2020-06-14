/*
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.
*/

// Problem Link: https://leetcode.com/problems/perfect-squares/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        int dp[n+1];
        dp[0]=0;
        
        vector<int> squares;
        for(int i=1; i<=n; i++)
        {
            if(isPerfectSquare(i))
            {
                squares.push_back(i);
                dp[i]=1; 
                continue; 
            }
            
            dp[i] = INT_MAX;
            for(auto x: squares)
                dp[i] = min(dp[i], 1+dp[i-x]); 
        }
        return dp[n];
    }

private:
    bool isPerfectSquare(int n)
    {
        float sr = sqrt(n); 
        return (sr - floor(sr) == 0); 
    }
};