/*
Given an input stream of N integers. The task is to insert these numbers into a new stream 
and find the median of the stream formed by each insertion of X to the new stream.
*/

#include <bits/stdc++.h>
using namespace std;

void printMedian(vector<int>& arr, int n) {
    
    priority_queue<int> l; 
    priority_queue<int, vector<int>, greater<int> > r; 
    
    double med = arr[0]; 
    l.push(arr[0]); 
    
    cout << floor(med) << "\n"; 
    
    for(int i=1; i<n; i++) {
        
        int x = arr[i]; 
        
        if(l.size() > r.size()) {
            
            if(x < med) {
                r.push(l.top()); 
                l.pop(); 
                l.push(x); 
            }
            
            else r.push(x); 
            
            med = (l.top()+r.top())/2; 
            cout << med << "\n"; 
        }
        
        else if(l.size() == r.size()) {
            if(x < med) {
                l.push(x); 
                med = l.top();
            }
            
            else {
                r.push(x); 
                med = r.top(); 
            }
            
            cout << med << "\n"; 
        }
        
        else if(l.size() < r.size()) {
            
            if(x < med) {
                l.push(x); 
            }
            
            else {
                l.push(r.top()); 
                r.pop(); 
                r.push(x); 
            }
            
            med = (l.top()+r.top())/2; 
            cout << med << "\n"; 
        }
    }
}

int main() {
	//code
	
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	
	int n; 
	cin >> n; 
	
	vector<int> arr(n); 
	for(int i=0; i<n; i++) {
	    cin >> arr[i]; 
	}
	
	printMedian(arr, n); 
	return 0;
}