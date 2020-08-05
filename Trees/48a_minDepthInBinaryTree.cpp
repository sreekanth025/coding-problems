/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node 
down to the nearest leaf node.
*/

// Problem Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        int left = minDepth(root->left), right = minDepth(root->right); 
        return 1 + (left&&right ? min(left, right) : max(left, right)); 
    }
};