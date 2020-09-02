#include<bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

void _helper(Node* root, unordered_map<int, pair<int,int>>& m, int hd, int d) {
    
    if(root == NULL) return; 
    
    if(m.find(hd) == m.end()) {
        m[hd] = make_pair(d, root->data); 
    }
    else {
        pair<int, int> p = m[hd]; 
        if(p.first <= d) {
            m[hd].first=d;
            m[hd].second=root->data; 
        }
    }
    
    _helper(root->left, m, hd-1, d+1); 
    _helper(root->right, m, hd+1, d+1); 
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   // map<int, pair<int, int>> m;
   unordered_map <int, pair<int, int>> m;
   vector<int> result;
   
   _helper(root, m, 0, 0); 
   
   
   /*
   for(auto p: m) {
       result.push_back(p.second.second); 
   }
   */
   
   vector<pair<int, int>> pre; 
   for(auto x: m) {
       pre.push_back({x.first, x.second.second}); 
   }
   
   sort(pre.begin(), pre.end());
   for(auto x: pre) result.push_back(x.second); 
   
   return result;
}