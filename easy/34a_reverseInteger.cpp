/*
Given a 32-bit signed integer, reverse digits of an integer.
*/

// Problem Link: https://leetcode.com/problems/reverse-integer/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool negative = x<0;
        x = abs(x); 
        int result=0; 
        while(x)
        {
            int rem = x%10; 
            if(result > INT_MAX/10 || (result==INT_MAX/10 && rem>7)) return 0;
            if(result < INT_MIN/10 || (result==INT_MIN/10 && rem<-8)) return  0; 
            result = result*10 + rem; 
            x/=10; 
        }
        if(negative) result = (-result);
        return result;
    }
};