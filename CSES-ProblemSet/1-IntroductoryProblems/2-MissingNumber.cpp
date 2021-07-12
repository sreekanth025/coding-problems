#include<bits/stdc++.h>
using namespace std;

// O(n) time, O(n) extra space
void method_1() {
    
    int n;
    cin >> n;

    int p;
    vector<bool> arr(n, false);
    for(int i=0; i<n-1; i++) {
        cin >> p;
        arr[p-1] = true;
    }

    for(int i=0; i<n; i++) {
        if(!arr[i]) {
            cout << i+1 << "\n";
            return;
        }
    }
}

int main() {
    method_1();
    return 0;
}