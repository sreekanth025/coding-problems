/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to 
the farthest leaf node.
*/

// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int max_depth=0; 
    int maxDepth(TreeNode* root) {
        max_depth=0; 
        _helper(root, 1); 
        return max_depth; 
    }

private: 
    void _helper(TreeNode* root, int depth)
    {
        if(root == NULL) return; 
        if(depth > max_depth) max_depth=depth; 
        
        _helper(root->left, depth+1); 
        _helper(root->right, depth+1); 
    }
};