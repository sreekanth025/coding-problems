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

void printSpiral(Node *root)
{
    if(root == NULL) return; 
    
    queue<Node* > q; 
    q.push(root);
    
    while(!q.empty()) {
        Node* s = q.front(); 
        q.pop();
        cout << s->data << " ";
        
        if(s->left != NULL) q.push(s->left); 
        if(s->right != NULL) q.push(s->right); 
    }
}