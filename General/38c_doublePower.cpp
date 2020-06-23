/*
Implement pow(x, n), which calculates x raised to the power n.
*/

// Problem Link: https://leetcode.com/problems/powx-n/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool negative = (n<0); 
        n = abs(n); 
        double result=1; 
        while(n>0)
        {
            if(n%2 == 1) result *= x; 
            x = x*x; 
            n/=2; 
        }
        if(negative) return 1/result;  
        return result;
    }
};