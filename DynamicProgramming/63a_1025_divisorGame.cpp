/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:

Choosing any x with 0 < x < N and N%x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.
*/

// Problem Link: https://leetcode.com/problems/divisor-game/

#include<bits/stdc++.h>
using namespace std; 

// Recursive Solution:
class Solution {
public:
    bool divisorGame(int N) {
        return _helper(N);
    }

private:
    bool _helper(int n) {
        if(n==1) return false; 
        // we cannot find x such that 0<x<1.
        
        for(int i=1; i<n; i++) {
            if(!(n%i) && !_helper(n-i)) return true;
        }
        return false;
    }
};

// Optimized using DP
class Solution {
public:
    int dp[1005]; 
    bool divisorGame(int N) {
        memset(dp, -1, sizeof(dp));
        return _helper(N);
    }

private:
    bool _helper(int n) {
        if(n==1) return false; 
        if(dp[n] != -1) return dp[n]; 
        
        for(int i=1; i<n; i++) {
            if(!(n%i) && !_helper(n-i)){
                dp[n] = 1;
                return true;
            } 
        }
        dp[n] = 0;
        return false;
    }
};


// Optimized DP
class Solution {
public:
    int dp[1005]; 
    bool divisorGame(int N) {
        memset(dp, -1, sizeof(dp));
        return _helper(N);
    }

private:
    bool _helper(int n) {
        if(n==1) return false; 
        if(dp[n] != -1) return dp[n]; 
        
        for(int i=1; i*i<n; i++) {
            if(!(n%i) && !_helper(n-i)){
                dp[n] = 1;
                if(i!=1) dp[n/i]=true;
                return true;
            } 
        }
        dp[n] = 0;
        return false;
    }
};

// Constant Time
class Solution {
public:
    bool divisorGame(int N) {
        return (N%2==0);
    }
};