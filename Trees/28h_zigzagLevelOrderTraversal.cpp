/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).
*/

// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<deque<int>> res; 
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        res.clear();
        _helper(root, 0); 
        
        vector<vector<int>> result; 
        for(int i=0; i<res.size(); i++)
        {
            result.push_back(vector<int>()); 
            for(auto x: res[i]) result[i].push_back(x);
        }
        return result;
    }

private:
    void _helper(TreeNode* root, int depth)
    {
        if(root==NULL) return; 
        if(res.size() == depth) res.push_back(deque<int>());
        
        if(depth%2 == 1) res[depth].push_front(root->val);  
        else res[depth].push_back(root->val);
        
        _helper(root->left, depth+1); 
        _helper(root->right, depth+1); 
    }
};