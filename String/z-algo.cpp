#include<bits/stdc++.h>
using namespace std; 

void zalgo(string s, vector<int>& z, int n)
{
    int L=0, R=0;
    z[0] = 0;

    for(int i=1; i<n; i++)
    {
        if(i > R)
        {
            L=R=i;
            while(R<n && s[R-L]==s[R]) R++; 
            z[i] = R-L;
            R--;   
        }    
        else
        {
            int k = i-L;
            if(z[k] < R-i+1) z[i]=z[k]; 
            else
            {
                L=i;
                while(R<n && s[R-L]==s[R]) R++;
                z[i] = R-L;
                R--;
            }
        }
    }
}

void search(string text, string pattern) 
{ 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
  
    vector<int> Z(l); 
    zalgo(concat, Z, l); 
  
    for (int i = 0; i < l; ++i) 
    { 
        if (Z[i] == pattern.length()) 
            cout << "Pattern found at index "
                << i - pattern.length() -1 << endl; 
    } 
} 
  
int main() 
{ 
    string text = "GEEKS FOR GEEKS"; 
    string pattern = "GEEK"; 
    search(text, pattern); 
    return 0; 
} 