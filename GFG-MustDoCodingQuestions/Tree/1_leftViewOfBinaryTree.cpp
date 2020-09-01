#include<bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void _helper(Node *root, vector<int>& result, int level) {
    
    if(root == NULL) {
        return;
    }
    
    if(result.size() == level) {
        result.push_back(root->data);
    }
    
    _helper(root->left, result, level+1);
    _helper(root->right, result, level+1); 
}

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
   vector<int> result; 
   _helper(root, result, 0);
   
   for(int x: result) {
       cout << x << " ";
   }
}