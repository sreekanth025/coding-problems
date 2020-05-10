/*
Given an unsorted array A of size N of non-negative integers, 
find a continuous sub-array which adds to a given number S. 
*/

#include<bits/stdc++.h>
using namespace std;

// Method_1: O(n^2) time complexity.
void method1(int arr[], int n, int sum)
{
    int current_sum, i, j;
    for(i=0; i<n; i++)
    {
        current_sum = arr[i]; 
        for(j=i+1; j<=n; j++)
        {
            if(current_sum == sum)
            {
                cout << "Subarray from index " << i << " to " << j << "\n";  
                return ;
            }

            if(current_sum > sum) break; 
            else current_sum += arr[j]; 
        }
    }

    cout << "No subarray exists with the given sum\n";
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    int sum = 23;  
    method1(arr, n, sum);
    return 0;  

}