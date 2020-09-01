#include <bits/stdc++.h>
using namespace std;

string solve() {
    vector<int> a(26,0), b(26,0); 
    string s1, s2; 
    
    cin >> s1 >> s2; 
    
    if(s1.size() != s2.size()) return "NO"; 
    
    for(int i=0; i<s1.size(); i++) {
        a[s1[i]-'a']++; 
    }
    
    for(int i=0; i<s2.size(); i++) {
        b[s2[i]-'a']++; 
    }
    
    for(int i=0; i<26; i++) {
        if(a[i] != b[i]) return "NO"; 
    }
    
    return "YES";
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