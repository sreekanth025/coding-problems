/*
Given a list of words, each word consists of English lowercase letters.
Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter 
anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, 
where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.
Return the longest possible length of a word chain with words chosen from the given list of words.
*/

// Problem Link: https://leetcode.com/problems/longest-string-chain/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size(); 
        if(n<=1) return n; 
        
        sort(words.begin(), words.end(), compare); 
        unordered_map<string, int> dp;
        int result=0; 
        
        for(string w: words) {
            for(int i=0; i<w.size(); i++) {
                dp[w] = max(dp[w], 1+dp[w.substr(0,i) + w.substr(i+1)]); 
            }
            result =  max(result, dp[w]); 
        }
        
        return result;
    }

private: 

    static bool compare(string& a, string& b) {
        return (a.size() < b.size()); 
    }
};


// Method 2: (Time Limit Exceeded)
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        int n = words.size(); 
        if(n<=1) return n; 
        
        sort(words.begin(), words.end(), compare); 
        vector<int> dp(n, 1); 
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(isPred(words[j], words[i]) && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1; 
                }
            }
        }
        
        int result=0;
        for(int x: dp) result = max(result, x); 
        
        return result; 
    }

private: 
    
    bool isPred(string a, string b) {
        
        vector<int> c1(26, 0), c2(26, 0); 
        for(char x: a) c1[x-'a']++; 
        for(char x: b) c2[x-'a']++; 
        
        bool diff = false; 
        
        for(int i=0;i<26; i++) {
            if(c1[i] != c2[i]) {
                if(abs(c1[i]-c2[i]) > 1) return false; 
                if(diff) return false;
                diff = true; 
            }
        }
        
        if(diff) return true; 
        return false; 
    }
    
    static bool compare(string& a, string& b) {
        return (a.size() < b.size()); 
    }
};