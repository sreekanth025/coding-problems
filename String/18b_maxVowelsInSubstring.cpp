/*
Given a string s and an integer k.
Return the maximum number of vowel letters in any substring of s with length k.
*/

// problem Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Time Complexity: O(n)

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size(); 
        vector<int> count(n, 0);
        
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
                count[0] = 1;
        else count[0] = 0; 
        
        for(int i=1; i<n; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                count[i] = count[i-1] + 1;
            else count[i] = count[i-1];
        }
        
        int max = count[k-1]; 
        for(int i=k; i<n; i++)
            if(count[i]-count[i-k] > max) max = count[i]-count[i-k];
        return max;
    }
};