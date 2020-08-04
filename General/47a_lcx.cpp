/*
Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  
On each player's turn, that player makes a move consisting of:
    - Choosing any x with 0 < x < N and N % x == 0.
    - Replacing the number N on the chalkboard with N - x.

Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.
*/

// Problem Link: https://leetcode.com/problems/divisor-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        return !(N&1);
    }
};

/*
Approach: 
1. A player cannot lose for both N and N+1: If N puts the player in a position to lose, 
   then at N+1 Alice can always force Bob into the N position by using 1 as her move.

2. A player wins if N is even: If N is even, then Alice can always choose 1 or 2 as her move. 
   Using property 1, this means that one of these moves must lead to a win. 

3. A player loses if N is odd: If N is odd, then the only moves Alice can make are odd. 
   An odd number - an odd number leaves Bob with an even number, which always leads to a win according to property 2.
*/