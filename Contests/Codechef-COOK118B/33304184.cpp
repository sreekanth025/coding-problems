#include<bits/stdc++.h>

#define int long long
#define num 1000000007

#define forn(x,n)	for(int x=0;x<n;x++)
using namespace std;

void zalgo(string s,vector<int>&z,int n){
	int l=0,r=0;
	z[0]=0;
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(r<n&&s[r-l]==s[r]) r++;
			z[i]=r-l;
			r--;
		}
		else {
			if(z[i-l]+i<=r)
			z[i]=z[i-l];
			else {
				l=i;
				while(r<n&&s[r-l]==s[r]) r++;
				z[i]=r-l;
				r--;
			}
		}
	}
}

void solve() {
	string str;
	cin>>str;
	int n=str.size(),ans=0;
	vector<int>a(n),b(n);

	zalgo(str,a,n);
	reverse(str.begin(), str.end()); 
	zalgo(str,b,n);

	for(int i=1;i<n-2;i++){
		if(a[i]>=i){
			int k=n-2*i;
			k/=2;
			if(k>0&&b[k]>=k) ans++;
		}
	}
	cout<<ans<<"\n";
}

int32_t main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int test_cases=1; 
	cin >> test_cases; 
	
	while(test_cases--)
        solve();
	return 0;
}
