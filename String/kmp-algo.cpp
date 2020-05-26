#include<bits/stdc++.h>
using namespace std;

void compute_lps_array(string pattern, int lps[])
{
    int m = pattern.size();
    int j = 0;

    lps[0] = 0;
    int i=1;

    while (i<m)
    {
        if(pattern[i] == pattern[j])
        { j++; lps[i]=j; i++; }

        else
        {
            if(j != 0) j=lps[j-1]; 
            else { lps[i]=0; i++; }
        }
    }
}

void KMP_Search(string pattern, string text)
{
    int m = pattern.size();
    int n = text.size();

    int lps[m];
    compute_lps_array(pattern, lps);
/*
    for(int i=0; i<m; i++)
      cout << lps[i] << " ";
  	cout << "\n";
*/
    int i=0, j=0;
    while(i<n)
    {
        // cout << i << "\n";
        if(pattern[j]==text[i]) { i++; j++; }
        if(j == m) 
        {
            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        }
        else if(i<n && pattern[j] != text[i])
        {
            if(j != 0) j=lps[j-1];
            else i++;
        }
    }
}

int main()
{
    string text = "ABABDABACDABABCABAB"; 
    string pattern = "ABABCABAB";
    KMP_Search(pattern, text);
    return 0;
}