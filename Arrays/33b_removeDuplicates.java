package Arrays;

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution_rd {
    public int removeDuplicates(int[] nums) {
        if(nums.length==0) return 0; 
        int i=0; 
        for(int j=1; j<nums.length; j++){
            if(nums[j] != nums[i]){
                nums[++i]=nums[j]; 
            }
        } 
        return i+1;
    }
}