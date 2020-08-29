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

Node* rotate(Node* head, int k)
{
    int count=0; 
    Node* first = head; 
    Node* result; 
    
    while(count < k-1) {
        head = head->next;
        count++; 
    }
    
    Node* last = head; 
    result = head->next; 
    
    if(result == NULL) return first;
    
    while(head->next != NULL) {
        head = head->next; 
    }
    
    head->next = first; 
    last->next = NULL;
    
    return result;
} 
