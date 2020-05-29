/*
Implement an iterator over a binary search tree (BST). 
Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST
*/

// Problem Link: https://leetcode.com/problems/binary-search-tree-iterator/

/*
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

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

// Method 1: Flatten the tree using inorder traversal
// Space Complexity: O(n)
// Time Complexity: O(n) for instantation and O(1) for both the required functions.

class BSTIterator {
public:
    
    vector<int> sortedNodes;
    int index;
    
    BSTIterator(TreeNode* root) {
        sortedNodes.clear();
        index = -1; 
        _inorder(root, sortedNodes);
    }
    
    /** @return the next smallest number */
    int next() {
        return sortedNodes[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (index+1) < sortedNodes.size();
    }
    
private:
    void _inorder(TreeNode* root,  vector<int>& sortedNodes)
    {
        if(root == NULL)
            return;
        
        _inorder(root->left, sortedNodes);
        sortedNodes.push_back(root->val);
        _inorder(root->right, sortedNodes);
    }
};


/*
==> next() and hasNext() should run in average O(1) time and uses O(h) memory, 
    where h is the height of the tree.
==> You may assume that next() call will always be valid, 
    that is, there will be at least a next smallest number in the BST when next() is called.
*/

// method 2: Controlled Recursion. 
// Space complexity: O(h)

class BSTIterator {
public:
    stack<TreeNode*> S;
    BSTIterator(TreeNode* root) {
        _leftMostInorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = S.top(); 
        S.pop();
        
        if(top->right != NULL)
            _leftMostInorder(top->right);
        
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(S.empty());
    }

private:
    void _leftMostInorder(TreeNode *root)
    {
        while(root != NULL)
        {
            S.push(root);
            root = root->left;
        }
    }
};