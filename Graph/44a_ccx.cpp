// Problem Link: https://www.codechef.com/problems/ECJN206

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
    int n; 
    string source, target; 
    cin >> n >> source >> target; 
    
    unordered_map<string, vector<string>> adj; 
    string a, b;
    
    forn(counter, n) {
        cin >> a >> b; 
        adj[a].pb(b); 
        adj[b].pb(a); 
    }
    
    queue<string> Q; 
    unordered_map<string, bool> visited; 
    
    bool reachable = false;
    
    Q.push(source); 
    visited[source] = true; 
    
    while(! Q.empty()) {
        string s = Q.front(); 
        Q.pop(); 
        
        bool stop = false;
        
        for(auto x: adj[s]) {
            
            if(x == target) {
                stop = true; 
                reachable = true; 
                break;
            }
            
            if(!visited[x]) {
                Q.push(x); 
                visited[x] = true; 
            }
        }
        
        if(stop) break; 
    }
    
    if(reachable) cout << "Quarantine\n"; 
    else cout << "Stay Home, Stay Safe\n";
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