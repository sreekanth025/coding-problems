/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
*/

// Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        _helper(root, 0, result); 
        return result;
    }
    
    void _helper(TreeNode* root, int depth, vector<vector<int>>& result)
    {
        if(root == NULL) return; 
        if(result.size() == depth) result.push_back(vector<int>());
            
        result[depth].push_back(root->val); 
        _helper(root->left, depth+1, result); 
        _helper(root->right, depth+1, result);
    }
};