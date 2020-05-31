/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

// Problem Link: https://leetcode.com/problems/validate-binary-search-tree/
// Approach: Check Inorder traversal.

#include<bits/stdc++.h>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        _inorder(root, arr); 
        
        if(arr.size() == 1) return true;
        for(int i=1; i<arr.size(); i++)
            if(arr[i] <= arr[i-1]) return false;
        return true;
     }

private: 
    void _inorder(TreeNode* root, vector<int>& arr)
    {
        if(root == NULL) return; 
        
        _inorder(root->left, arr); 
        arr.push_back(root->val); 
        _inorder(root->right, arr);
    }
};