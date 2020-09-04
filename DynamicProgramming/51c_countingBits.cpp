/*
Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their 
binary representation and return them as an array.
*/

// Problem Link: https://leetcode.com/problems/counting-bits/

#include<bits/stdc++.h> 
using namespace std; 

// Best Method:
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);  
        result[0]=0; 
        
        for(int i=1; i<=n; i++) {
            result[i] = result[i>>1] + (i%2); 
        } 
        
        return result;
    }
};

// Method 2: 
class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result; 
        result.push_back(0); 
        
        vector<int> tmp(1,1); 
        
        while(result.size() < n+1) {
            result.insert(result.end(), tmp.begin(), tmp.end()); 
            
            vector<int> p = tmp; 
            for(int i=0; i<p.size(); i++) p[i]++; 
            
            tmp.insert(tmp.end(), p.begin(), p.end()); 
        }
        
        /*
        vector<int> res; 
        for(int i=0; i<=n; i++) {
            res.push_back(result[i]); 
        }
        
        return res;
        */
        
        while(result.size() > n+1) result.pop_back(); 
        return result;
    } 
};


