/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/

// O(n) - Time Complexity: 

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1; 
        
        int area = 0; 
        while(left < right)
        {
            int t_area = min(height[left], height[right])*(right-left); 
            if(t_area > area)
                area = t_area; 
            
            if(height[left] < height[right])
                left++; 
            else right--;
        }
        
        return area;
    }
};

// code contains only the required function. 
/*
Problem Link: 
https://leetcode.com/problems/container-with-most-water/
*/
