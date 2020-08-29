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

struct Node* reverseList(struct Node *head)
{
    Node* current; 
    Node* next; 
    Node* prev; 
    
    current = head;
    next = head->next;
    prev = NULL; 
    
    if(next == NULL) return head; 
    
    while(next != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;
        current = next; 
    }
    
    return prev; 
}