/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.
*/

// Problem link: https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; 
        recursion(root, 1, result); 
        return result;
    }
private: 
    void recursion(TreeNode* root, int level, vector<int>& result)
    {
        if(root == NULL) return; 
        if(result.size() < level) result.push_back(root->val); 
        
        recursion(root->right, level+1, result);
        recursion(root->left, level+1, result);
    }
};