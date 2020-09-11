/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/

// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n<=1) return 0;  
        
        vector<int> s0(n,0), s1(n,0), s2(n,0);
        
        s1[0] = -prices[0];
        //s2[0] = INT_MIN;
        
        for(int i=1; i<n; i++) {
            s0[i] = max(s0[i-1], s2[i-1]); 
            s1[i] = max(s1[i-1], s0[i-1]-prices[i]); 
            s2[i] = s1[i-1] + prices[i]; 
        }
        
        return max(s0[n-1], s2[n-1]);
    }
};