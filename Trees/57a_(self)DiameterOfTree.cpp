#include<bits/stdc++.h> 
using namespace std; 

int x; 

void dfsUtil(int node, int count,  bool visited[], int& max_count, list<int>* adj) {
    visited[node]=true;
    count++; 

    for(auto i=adj[node].begin(); i!=adj[node].end(); i++) {
        if(!visited[*i]) {
            if(count >= max_count) {
                max_count = count;
                x = *i; 
            }

            dfsUtil(*i, count, visited, max_count, adj); 
        }
    }
}

void dfs(int node, int n, list<int>* adj, int& max_count) {
    bool visited[n+1]; 
    memset(visited, false, sizeof(visited)); 
    int count=0; 

    dfsUtil(node, count+1, visited, max_count, adj); 
}

int diameter(list<int>* adj, int n) {

    int max_count = INT_MIN; 
    dfs(1, n, adj, max_count); 
    dfs(x, n, adj, max_count); 

    return max_count; 
}

int main() {

    int n=5; 

/* Example tree:
         1 
        / \ 
        2    3 
       / \ 
      4   5 
*/

    list<int>* adj = new list<int>[n+1]; 

    adj[1].push_back(2); 
    adj[2].push_back(1); 

    adj[1].push_back(3); 
    adj[3].push_back(1); 

    adj[2].push_back(4); 
    adj[4].push_back(2);
     
    adj[2].push_back(5); 
    adj[5].push_back(2); 

    cout << "Diameter of tree: " << diameter(adj, n); 
    return 0; 
}