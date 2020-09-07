#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; 
    cin >> n; 
    
    int arr[n]; 
    for(int i=0; i<n; i++) cin >> arr[i]; 
    
    if(n==0 || arr[0]==0) return -1; 
    
    vector<int> res(n, INT_MAX); 
    
    res[0]=0; 
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(i <= j+arr[j]) {
                res[i] = min(res[i], res[j]+1); 
            }
        }
    }
    
    return (res[n-1]==INT_MAX) ? -1:res[n-1]; 
}

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    
    int test_cases=1; 
    cin >> test_cases; 
    
    while(test_cases--) {
        cout << solve() << "\n"; 
    }
	return 0;
}