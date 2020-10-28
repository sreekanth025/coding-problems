#include<bits/stdc++.h>
using namespace std; 

#define INF 1e9+7

int partition(int *arr, int low, int high) {
    int p = low;  
    int i=low, j=high; 

    while(i<j) {

        do{i++;} while(i<high && arr[i] <= arr[p]);
        do{j--;} while(j>low && arr[j] > arr[p]);
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[p], arr[j]); 
    return j;
}

void quick_sort(int *arr, int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);  
        quick_sort(arr, low, p); 
        quick_sort(arr, p+1, high);
    }
}

int main() {

    // freopen("input.txt", "r", stdin);

    int tc; 
    cin >> tc;

    while(tc--) {
        
        int n;
        cin >> n; 

        int arr[n+1];
        for(int i=0; i<n; i++) cin >> arr[i];
        arr[n] = INF; 

        quick_sort(arr, 0, n);
        for(int i=0; i<n; i++) cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}

/*
Input: 

6
6
10 7 8 9 1 5
6
12 11 13 5 6 7
7
-5 -10 0 -3 8 5 -1 10 
8
170 45 75 90 802 24 2 66
5
5 21 7 23 19
7
8 3 2 7 4 6 8

*/