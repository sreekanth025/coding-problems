/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
Return the length of the longest subarray that contains only 1s. 
*/

// Problem link: https://leetcode.com/problems/max-consecutive-ones-iii/
// Translation: Find the longest subarray with at most K zeros.

/*
For each A[j], try to find the longest subarray.
If A[i] ~ A[j] has zeros <= K, we continue to increment j.
If A[i] ~ A[j] has zeros > K, we increment i. 
*/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int i=0, j;
        for(j=0; j<A.size(); j++)
        {
            k -= 1-A[j]; 
            if(k < 0) k += 1-A[i++]; 
        }
        
        return j-i; 
    }
};