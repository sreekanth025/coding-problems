// Problem Link: https://www.codechef.com/problems/CFS2005

#include<bits/stdc++.h> 
using namespace std; 

#define int long long

#define N 2*1e5+5
const int mod = 998244353;

vector<int> fact(N);
void preprocess() { 
    fact[0]=fact[1]=1; 
    for(int i=2; i<N; i++) {
        fact[i] = fact[i-1]*i%mod; 
    }
}

int powr(int a, int n) {

    int res=1;
    while(n) {
        if(n&1) res = res*a%mod; 
        a = a*a%mod; 
        n/=2; 
    }
    return res; 
}

int ncr(int n, int r) {
    
    int num = fact[n]; 
    int den = fact[r]*fact[n-r]%mod; 
    return num*powr(den, mod-2)%mod;
}

int solve() {
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2; 

    int total = ncr(n+m, n); 


    int xa = ncr(x1+y1, x1); 
    int xb = ncr(n-x1+m-y1, n-x1); 
    
    int ya = ncr(x2+y2, x2); 
    int yb = ncr(n-x2+m-y2, n-x2); 


    int r1 = ncr(x1+y1,x1); 
    int r2 = ncr(x2-x1+y2-y1, x2-x1); 
    int r3 = ncr(n-x2+m-y2, n-x2); 

    int rest = r1*r2%mod;
    rest = rest*r3%mod; 

    return (total + 2*mod - xa*xb%mod - ya*yb%mod + rest)%mod;
}

int32_t main() {

    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    // freopen("input.txt", "r", stdin);
    preprocess();

    int tc=1; 
    cin >> tc; 

    while(tc--) {
        cout << solve() << "\n";
    }

    return 0; 
}