#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    int n;
    cin >> n; 
    
    int arr[n+1]; 
    arr[0] = 0; 
    arr[1] = 1; 
    for(int i=2; i<=n; i++) {
        if(i&1) arr[i] = 1+arr[i-1]; 
        else arr[i] = 1+min(arr[i/2], arr[i-1]); 
    }
    
    cout << arr[n] << "\n";
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        solve();
	return 0;
}