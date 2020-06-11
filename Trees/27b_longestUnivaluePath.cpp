/*
Given a binary tree, find the length of the longest path where each node 
in the path has the same value. This path may or may not pass through the root.
The length of path between two nodes is represented by the number of edges between them.
*/

// Problem link: https://leetcode.com/problems/longest-univalue-path/

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
    int longestUnivaluePath(TreeNode* root) {
        int result=0; 
        if(root) dfs(root, result); 
        return result; 
    }
    
private: 
    int dfs(TreeNode* root, int& result)
    {
        int l = root->left ? dfs(root->left, result) : 0; 
        int r = root->right ? dfs(root->right, result) : 0; 
        
        int res_l = root->left && root->left->val == root->val ? l+1:0; 
        int res_r = root->right && root->right->val == root->val ? r+1:0; 
        
        result = max(result, res_l+res_r); 
        return max(res_l, res_r); 
    }
};