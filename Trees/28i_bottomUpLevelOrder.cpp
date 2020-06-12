/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
*/

// Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

// Method 1:
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result; 
        _helper(root, 0, result); 
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    void _helper(TreeNode* root, int depth, vector<vector<int>>& result)
    {
        if(root == NULL) return; 
        if(result.size() == depth) result.push_back(vector<int>());
            
        result[depth].push_back(root->val); 
        _helper(root->left, depth+1, result); 
        _helper(root->right, depth+1, result);
    }
};

// Method 2: 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = _depth(root);
        vector<vector<int>> result(d, vector<int>()); 
        _helper(root, d-1, result);
        return result;  
    }
    
private: 
    int _depth(TreeNode* root)
    {
        if(root == NULL) return 0; 
        return max(_depth(root->left), _depth(root->right))+1;
    }
    
    void _helper(TreeNode* root, int depth, vector<vector<int>>& result) 
    {
        if(root == NULL) return; 
        
        result[depth].push_back(root->val); 
        _helper(root->left, depth-1, result); 
        _helper(root->right, depth-1, result);
    }
};