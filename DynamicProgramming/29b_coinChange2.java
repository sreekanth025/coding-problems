package DynamicProgramming; 

/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount. 
You may assume that you have infinite number of each kind of coin.
*/

// Problem Link: https://leetcode.com/problems/coin-change-2/

import java.util.Arrays; 
class Solution_x {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount+1]; 
        Arrays.fill(dp, 0);
        
        dp[0]=1; 
        for(int x: coins)
            for(int i=1; i<=amount; i++)
                if(i>=x) dp[i] += dp[i-x]; 
        
        return dp[amount];
    }
}