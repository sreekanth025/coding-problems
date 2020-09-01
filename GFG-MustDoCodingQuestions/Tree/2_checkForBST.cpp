#include<bits/stdc++.h>
using namespace std; 

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int isBSTUtil(Node* root, int min, int max) {
    
    if(root==NULL) return 1;
    if(root->data < min || root->data > max) return 0; 
    
    return (isBSTUtil(root->left, min, root->data-1) 
            && isBSTUtil(root->right, root->data+1, max)); 
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
