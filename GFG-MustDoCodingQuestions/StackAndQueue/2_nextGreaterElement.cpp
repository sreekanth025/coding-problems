#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; 
    cin >> n; 
    
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i]; 
    
    vector<int> result(n,-1); 
    stack<int> stk; 
    
    for(int i=0; i<n; i++) {
        
        while(!stk.empty() && arr[stk.top()] < arr[i]) {
            result[stk.top()] = arr[i]; 
            stk.pop(); 
        }
        
        stk.push(i); 
    }
    
    for(int x: result) {
        cout << x << " "; 
    }
    cout << "\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	
	int test_cases=1; 
	cin >> test_cases; 
	
	while(test_cases--) {
	    solve(); 
	}
	return 0;
}