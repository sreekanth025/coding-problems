/*
Given an input stream of n integers, find the kth largest element for each element in the stream
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, n; 
    cin >> k >> n; 
    
    int arr[k]; 
    int x; 
    int kmax;
    priority_queue<int, vector<int>, greater<int> > heap; 
    for(int num=0; num<n; num++) {
        
        cin >> x; 
        if(num < k-1) {
            arr[num] = x; 
            cout << -1 << " "; 
        }
        
        else if(num==k-1) {
            arr[num] = x; 
            for(int i=0; i<k; i++) {
                heap.push(arr[i]); 
            }
            kmax = heap.top(); 
            cout << kmax << " ";
        }
        
        else {
            if(x > kmax) {
                heap.pop(); 
                heap.push(x);
                kmax = heap.top(); 
            }
            cout << kmax << " ";
        }
    }
    
    cout << "\n"; 
}

int main() {
	//code
	int test_cases=1; 
	cin >> test_cases; 
	while(test_cases--) {
	    solve(); 
	}
	
	return 0;
}