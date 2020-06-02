/*
Given a rectangular cake with height h and width w, and two arrays of integers 
horizontalCuts and verticalCuts where horizontalCuts[i] is the distance 
from the top of the rectangular cake to the ith horizontal cut and similarly, 
verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position 
provided in the arrays horizontalCuts and verticalCuts. 
Since the answer can be a huge number, return this modulo 10^9 + 7.
*/

// Problem Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/


#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long long mod = 1e9 + 7;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int max_h = horizontalCuts[0]; 
        for(int i=1; i<horizontalCuts.size(); i++)
            max_h = max(max_h, horizontalCuts[i]-horizontalCuts[i-1]);
        max_h = max(max_h, h-horizontalCuts.back());
        
        int max_v = verticalCuts[0];  
        for(int i=1; i<verticalCuts.size(); i++)
            max_v = max(max_v, verticalCuts[i]-verticalCuts[i-1]); 
        max_v = max(max_v, w-verticalCuts.back());
            
        long long a=max_v, b=max_h;
        return (a*b)%mod;
    }
};