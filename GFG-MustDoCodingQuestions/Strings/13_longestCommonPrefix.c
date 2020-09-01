#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n; 
    cin >> n; 
    
    vector<string> arr(n);
    int minl = 1e4; 
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        
        if(arr[i].size() < minl) {
            minl = arr[i].size(); 
        }
    }
    
    string result = ""; 
    for(int ind=0; ind<minl; ind++) {
        
        char x = arr[0][ind]; 
        bool next = true; 
        
        for(int i=1; i<n; i++) {
            if(arr[i][ind] != x) {
                next=false;
                break; 
            }
        }
        
        if(!next) {
            if(result.size()==0) return "-1"; 
            else return result; 
        }
        
        result.push_back(x); 
    }
    
    if(result.size()==0) return "-1"; 
    return result; 
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int test_cases=1; 
    cin >> test_cases; 
    while(test_cases--) {
        cout << solve() << "\n"; 
    }
	return 0;
}