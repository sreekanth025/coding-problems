/*
Given a binary tree, return the inorder traversal of its nodes' values.
*/

// Problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        _helper(root, result); 
        return result;
    }
    
    void _helper(TreeNode* root, vector<int>& result)
    {
        if(root == NULL) return; 
        
        _helper(root->left, result); 
        result.push_back(root->val); 
        _helper(root->right, result); 
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        stack<TreeNode*> s; 
        
        TreeNode* current = root; 
        while(current != NULL || !s.empty())
        {
            while(current != NULL)
            {
                s.push(current); 
                current = current->left; 
            }
            
            current = s.top(); 
            s.pop();
            result.push_back(current->val); 
            current = current->right; 
        }
        
        return result;
    }
};