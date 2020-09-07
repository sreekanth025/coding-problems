/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n
*/

// Problem Link: https://leetcode.com/problems/count-numbers-with-unique-digits/

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0) return 1; 
        
        int dp[n+1]; 
        dp[0]=0; 
        dp[1]=10; 
        
        for(int i=2; i<=n; i++) {
            dp[i]=9; 
            
            for(int j=9; j>=11-i; j--) {
                dp[i] *= j; 
            }
        }
        
        int result=0; 
        for(int x: dp) result += x; 
        return result; 
    }
};