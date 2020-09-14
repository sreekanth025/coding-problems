/*
Given two arrays of integers nums1 and nums2, 
return the number of triplets formed (type 1 and type 2) under the following rules:

Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] 
        where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] 
        where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
*/

// Problem Link: https://leetcode.com/problems/number-of-ways-where-square-of-number-is-equal-to-product-of-two-numbers/

#include<bits/stdc++.h> 
using namespace std; 

#define ll long long

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size(), n2=nums2.size(); 
        unordered_map<ll,ll> scount1, scount2; 
        
        for(ll x: nums1) scount1[x*x]++; 
        for(ll x: nums2) scount2[x*x]++; 
        
        int ans=0; 
        for(int i=0; i<n1; i++) {
            for(int j=i+1; j<n1; j++) {
                ans += scount2[(ll)nums1[i] * (ll)nums1[j]]; 
            }
        }
        for(int i=0; i<n2; i++) {
            for(int j=i+1; j<n2; j++) {
                ans += scount1[(ll)nums2[i] * (ll)nums2[j]]; 
            }
        }
        
        return ans;  
    }
};