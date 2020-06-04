/*
Write a function that reverses a string. 
The input string is given as an array of characters char[].
Do not allocate extra space for another array, you must do this by modifying 
the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.
*/

// Problem link: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3350/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        
        while(left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            
            left++;
            right--;
        }
    }
};