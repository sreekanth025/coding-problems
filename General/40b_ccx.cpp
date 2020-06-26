// Problem Link: https://www.codechef.com/problems/TADELIVE

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
#define sp printf(" ")

bool compare(pair<int,int> a, pair<int, int> b)
{
    return a.first > b.first;
}

void solve()
{
   int n, x, y; 
   cin >>n>>x>>y; 
   
   int a[n], b[n];
   
   forn(i,n) cin >> a[i]; 
   forn(i,n) cin >> b[i];
   
   vector<pair<int, int>> loss; 
   forn(i,n) loss.pb({abs(a[i]-b[i]), i}); 
   sort(all(loss), compare); 
   
   int al=0, bob=0; 
   int result = 0; 
   for(auto l: loss)
   {
       int index = l.second; 
       if(a[index] > b[index]){
           
           if(al < x)  {
               result += a[index]; 
               al++; 
           }
           else{
               result += b[index]; 
               bob++; 
           }
       }
       
       else {
           if(bob < y) {
               result += b[index];
               bob++;
           }
           else {
               result += a[index]; 
               al++;
           }
       }
   }
   
   cout << result << nl;
}

int32_t main() {
	// your code goes here
    fast;
	int test_cases=1; 
	// cin >> test_cases; 
	while(test_cases--)
        solve();
	return 0;
}