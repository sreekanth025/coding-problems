package Arrays;

/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

// Problem Link: https://leetcode.com/problems/remove-element/

class Solution_re {
    public int removeElement(int[] nums, int val) {
        if(nums.length == 0) return 0; 
        
        int fast=0, slow=0; 
        for(fast=0; fast < nums.length; fast++)
        {
            if(nums[fast] != val)
                nums[slow++]=nums[fast]; 
        }
        
        return slow; 
    }
}