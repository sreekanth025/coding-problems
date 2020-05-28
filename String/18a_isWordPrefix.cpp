/*
Given a sentence that consists of some words separated by a single space, and a searchWord.
You have to check if searchWord is a prefix of any word in sentence.
Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).
If searchWord is a prefix of more than one word, return the index of the first word (minimum index). 
If there is no such word return -1.
A prefix of a string S is any leading contiguous substring of S.
*/

// Problem link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        if(searchWord.size() > sentence.size()) return -1; 
        if(sentence == searchWord) return 0; 
        
        int n = searchWord.size(); 
        stringstream s(sentence);
        
        string word; 
        int i=0;
        
        while(s >> word)
        {
            i++; 
            if(word.substr(0, n) == searchWord) return i; 
        }
        return -1;
    }
};