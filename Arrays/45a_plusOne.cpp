/* 
- Given a non-empty array of digits representing a non-negative integer, 
  increment one to the integer.
- The digits are stored such that the most significant digit is at the head of the list, 
  and each element in the array contains a single digit.
- You may assume the integer does not contain any leading zero, except the number 0 itself.
*/

// Problem Link: https://leetcode.com/problems/plus-one/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(); 
        for(int i=n-1; i>=0; i--) {
            if(digits[i] != 9) {
                digits[i]++; 
                return digits;  
            }
            
            digits[i]=0; 
        }
        
        vector<int> result; 
        result.push_back(1); 
        result.insert(result.end(), digits.begin(), digits.end()); 
        return result;
    }
};