#include<bits/stdc++.h>
using namespace std; 

vector <int> bfs(vector<int> g[], int n) {

    queue<int> q; 
    vector<bool> visited(n,false); 
    vector<int> result; 
    
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()) {
        int v = q.front(); 
        q.pop(); 
        result.push_back(v);
        
        for(int x: g[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }
    
    return result;
    
}