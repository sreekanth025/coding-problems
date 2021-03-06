/*
You're given strings J representing the types of stones that are jewels, 
and S representing the stones you have. Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.
The letters in J are guaranteed distinct, and all characters in J and S are letters. 
Letters are case sensitive, so "a" is considered a different type of stone from "A".
*/

// Problem Link: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> jewels;
        for(auto x:J) jewels[x] = true; 
        
        int result = 0; 
        for(auto x:S) if(jewels[x]) result++;
        return result; 
    }
};