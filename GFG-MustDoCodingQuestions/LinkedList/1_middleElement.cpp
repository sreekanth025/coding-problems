#include<bits/stdc++.h>
using namespace std; 

typedef struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
} Node;

int getMiddle(Node *head)
{
    Node* slow; 
    Node* fast; 
    
    slow = fast = head; 
    while(1) {
        if(fast->next == NULL) return slow->data;
        fast = fast->next; 
        slow = slow->next;
        
        if(fast->next == NULL) return slow->data;
        fast = fast->next;
    }
} 
