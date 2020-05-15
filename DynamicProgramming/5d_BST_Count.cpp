/*
Given n, how many structurally unique BST's (binary search trees) 
that store values 1 ... n?
*/

// Time Complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        
        int count[n+1];
        memset(count, 0, sizeof(count)); 
        count[0] = count[1] = 1; 
        
        for(int i=2; i<=n; i++)
            for(int j=1; j<=i; j++)
                count[i] += count[i-j]*count[j-1];
        
        return count[n];
    }
};

// Code contains only the required functions. 
// Problem link: https://leetcode.com/problems/unique-binary-search-trees/