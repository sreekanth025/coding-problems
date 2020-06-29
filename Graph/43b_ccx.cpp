// Problem Link: https://www.codechef.com/ENJU2020/problems/ECJN205

#include<bits/stdc++.h>
using namespace std;

#define rg register
#define In inline
#define ll long long
#define int long long

#define REP(i,start,end) for(rg int i=start; i<=end; i++)
#define RREP(i,end,start) for(rg int i=end; i>=start; i--)
#define forn(i, n) for(rg int i=0; i<n; i++)

#define eps 1e-9
const ll mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define Vi vector<int>
#define all(a) a.begin(),a.end()
#define pb push_back
#define set0(a) memset(a, 0, sizeof(a))
#define setneg(a) memset(a, -1, sizeof(a))

#define nl "\n"
#define sp " "

void solve()
{
    int n, m;
    cin >> n >> m; 
   
    vector<int> adj[n+1]; 
    unordered_map<int, bool> treat;
   
    int t;
    forn(i,m) {
        cin >> t;
        treat[t] = true;
    }
   
    int p;
    cin >> p;

    int a, b;
    forn(i,p) {
        cin >> a >> b; 
        adj[a].pb(b);
        adj[b].pb(a); 
    }
   
    int source, target; 
    cin >> source >> target; 
    
    if(source == target) {
        cout << "0\n"; 
        return;
    }
    
    bool exist = false; 
    Vi parent(n+1,-1); 
    vector<bool> visited(n+1, false); 
    
    queue<int> Q;
    Q.push(source); 
    visited[source] = true;
    
    while(! Q.empty()) {
        int s = Q.front(); 
        Q.pop(); 
        
        bool stop = false; 
        
        for(auto x: adj[s]) {
            if(!visited[x] && treat[x]) {
             
                visited[x] = true; 
                Q.push(x); 
                parent[x]=s; 
                
                if(x == target) {
                    exist = true;
                    stop = true; 
                    break;
                }
            }   
        }
        
        if(stop) break; 
    }
    
    if(! exist) { cout << "-1\n"; return; }
    
    int result = 0; 
    int current = target; 
    while(current != source)
    {
        result++; 
        current = parent[current];
    }
    
    cout << result << nl;
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	cin >> test_cases; 
	while(test_cases--)
        solve();
        // cout << solve() << nl;
	return 0;
}

/*
1
5 3
1 2 3
7
1 2
1 3
2 4
2 5
4 5
2 3
1 4
1 2
*/