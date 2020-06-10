/*
You have a browser of one tab where you start on the homepage and you can visit another url, 
get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:
--> BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
--> void visit(string url) visits url from the current page. It clears up all the forward history.
--> string back(int steps) Move steps back in history. If you can only return x steps in the history and 
    steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
--> string forward(int steps) Move steps forward in history. If you can only forward x steps in the history 
    and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
*/

// Problem link: https://leetcode.com/problems/design-browser-history/

#include<bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    
    stack<string> backward_stack; 
    stack<string> forward_stack; 
    
    BrowserHistory(string homepage) {
        backward_stack.push(homepage);
    }
    
    void visit(string url) {
        backward_stack.push(url);
        
        while(!forward_stack.empty())
            forward_stack.pop();
    }
    
    string back(int steps) {
        int k = backward_stack.size()-1;
        steps = min(steps, k); 
        
        string result = backward_stack.top(); 
        while(steps--) result = single_backward_step();
        return result;
    }
    
    string forward(int steps) {
        int k = forward_stack.size();
        steps = min(steps, k); 
        
        string result = backward_stack.top(); 
        while(steps--) result = single_forward_step();
        return result;
    }
    
private: 
    string single_backward_step()
    {
        string top = backward_stack.top(); 
        forward_stack.push(top); 
        backward_stack.pop(); 
        return backward_stack.top();
    }
    
    string single_forward_step()
    {
        string top = forward_stack.top(); 
        backward_stack.push(top); 
        forward_stack.pop();  
        return top;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */