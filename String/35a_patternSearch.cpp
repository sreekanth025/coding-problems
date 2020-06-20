/*
Return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
*/

// Problem link: https://leetcode.com/problems/implement-strstr/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()==0 && needle.size()==0) return 0;
        if(haystack.size()==0) return -1; 
        if(needle.size()==0) return 0; 
        
        string text = needle + '$' + haystack; 
        vector<int> z(text.size()); 
        zalgo(text, z); 
        
        int i=needle.size(); 
        while(i<text.size()){
            if(z[i]>=needle.size()) return i-needle.size()-1;
            i++;
        }  
        return -1; 
    }
    
    void zalgo(string text, vector<int>& z)
    {
        int L=0, R=0; 
        int n=text.size(); 
        
        z[0]=0; 
        for(int i=1; i<n; i++)
        {
            if(i>R)
            {
                L=R=i; 
                while(R<n && text[R-L]==text[R]) R++; 
                z[i] = R-L; 
                R--; 
            }
            else
            {
                int k = i-L;
                if(z[k] < R-i+1) z[i]=z[k]; 
                else 
                {
                    L=i; 
                    while(R<n && text[R-L]==text[R]) R++; 
                    z[i]=R-L;
                    R--;
                }
            }
        }
    }
};