// Problem Link: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve() {
    string s; 
    cin >> s; 
    vector<string> words; 
    
    string word = ""; 
    for(int i=0; i<s.size(); i++) {
        if(s[i] != '.') {
            word.push_back(s[i]); 
        }
        
        else {
            words.push_back(word); 
            word = "";
        }
    }
    words.push_back(word); 
    
    reverse(words.begin(), words.end()); 
    string result = ""; 
    for(auto x: words) {
        result.append(x); 
        result.push_back('.');
    }
    
    result = result.substr(0, result.size()-1); 
    cout << result << "\n";
}

int main() {
    fast; 
    int test_cases = 1; 
    cin >> test_cases;
    while(test_cases--) 
        solve();
	return 0;
}