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

void solve(){}

#define px first
#define py second 
#define pairll pair<ll, ll> 

int compare(pairll a, pairll b){return a.px<b.px;}
double closestPair(pairll points[], int n)
{
    sort(points, points+n, compare); 
    double best = INF;
    set<pairll> box; 
    box.insert(points[0]); 

    int left=0; 
    REP(i,1,n-1)
    {
        while(left<i && points[i].px-points[left].px > best)
            box.erase(points[left++]); 
        for(typeof(box.begin()) it=box.lower_bound(make_pair(points[i].py-best, points[i].px-best)); 
            it != box.end() && points[i].py+best >= it->py; it++)
            best = min(best, sqrt(pow(points[i].py - it->py, 2.0)+pow(points[i].px-it->px, 2.0))); 
        box.insert(points[i]); 
    }

    return best; 
}

int32_t main() {
	// your code goes here
    fast;
    /*
	int test_cases=1; 
	cin >> test_cases; 
	while(test_cases--)
        solve();
    */

    pairll points[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(points)/sizeof(points[0]); 
    cout << "The smallest distance is " << closestPair(points, n);  
    return 0;  
}