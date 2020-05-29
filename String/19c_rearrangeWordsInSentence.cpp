/*
Given a sentence text (A sentence is a string of space-separated words) in the following format:
First letter is in upper case.
Each word in text are separated by a single space.
Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. 
If two words have the same length, arrange them in their original order.
Return the new text following the format shown above.
*/

// Problem Link: https://leetcode.com/problems/rearrange-words-in-a-sentence/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    string arrangeWords(string text) {
        text[0] = text[0]-'A'+'a';  
        string word; 
        stringstream s(text); 
        
        map<int, vector<string>> words;
        while(s >> word)
            words[word.size()].push_back(word);
        
        string output = "";
        for(auto x: words)
            for(auto w: x.second)
                output.append(w + " ");
        
        output = output.substr(0, output.size()-1);
        output[0] = output[0]-'a'+'A';
        return output;
    }
};