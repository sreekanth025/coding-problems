/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*/

// Problem Link: https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        return _helper(root, root);
    }
    
private:
    bool _helper(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL && root2==NULL) return true; 
        if(root1==NULL || root2==NULL) return false; 
        
        return (root1->val==root2->val) && _helper(root1->left, root2->right) 
                && _helper(root1->right, root2->left); 
    }
};