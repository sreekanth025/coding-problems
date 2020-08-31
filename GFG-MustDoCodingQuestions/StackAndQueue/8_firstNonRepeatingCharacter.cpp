#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n; 
    
    char x; 
    unordered_map<char, int> cnt; 
    queue<char> q; 
    
    for(int i=0; i<n; i++) {
        cin >> x; 
        if(cnt[x]==0) {
            q.push(x); 
        }
        
        cnt[x]++;
        
        if(cnt[x] > 1) {
            while(!q.empty() && cnt[q.front()] > 1)
                q.pop(); 
        }
        
        if(q.empty()) cout << -1 << " "; 
        else {
            cout << q.front() << " "; 
        }
    }
    cout << "\n";
}

int main() {
	
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	
	int test_cases=1; 
	cin >> test_cases; 
	
	while(test_cases--) {
	    solve(); 
	}
	
	return 0;
}