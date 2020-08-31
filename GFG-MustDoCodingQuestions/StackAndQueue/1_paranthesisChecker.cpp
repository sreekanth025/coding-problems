#include <bits/stdc++.h>
using namespace std;

string solve() {
    string s; 
    cin >> s; 
    
    int n=s.size(); 
    if(n&1) return "not balanced"; 
    
    stack<char> stk; 
    for(int i=0; i<n; i++) {
        
        if(s[i]=='{' || s[i]=='(' || s[i]=='[') {
            stk.push(s[i]); 
            continue; 
        }
        
        if(stk.empty()) return "not balanced"; 
        
        if(s[i]=='}') {
            char tmp = stk.top(); 
            stk.pop(); 
            if(tmp != '{') return "not balanced"; 
        }
        
        else if(s[i]==')') {
            char tmp = stk.top(); 
            stk.pop(); 
            if(tmp != '(') return "not balanced";
        }
        
        else if(s[i]==']') {
            char tmp = stk.top(); 
            stk.pop(); 
            if(tmp != '[') return "not balanced";
        }
    }
    
    if(stk.empty()) return "balanced"; 
    return "not balanced";
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