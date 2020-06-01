/*
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend of B, 
and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. 
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. 
And you have to output the total number of friend circles among all the students.
*/

// Problem Link: https://leetcode.com/problems/friend-circles/

#include<bits/stdc++.h>
using namespace std; 


// method 1: DFS

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int n = M.size(); 
        
        vector<bool> visited(n, false);
        int result = 0; 
        
        for(int i=0; i<n; i++)
            result += !visited[i] ? dfs(i, M, visited), 1:0; 
        
        return result;
    }
    
private:
    void dfs(int i, vector<vector<int>>& M, vector<bool>& visited)
    {
        visited[i] = true; 
        for(int j=0; j<M.size(); j++)
            if(i!=j && M[i][j] && !visited[j])
                dfs(j, M, visited);
        return;
    }
};

// method 2: Union-Find

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(); 
        vector<int> p(n, 0); 
        for(int i=0; i<p.size(); i++)
            p[i] = i; 
        
        int result = n;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(M[i][j] == 1)
                {
                    int node1 = i; 
                    while(node1 != p[node1]) node1 = p[node1]; 
                    
                    int node2 = j; 
                    while(node2 != p[node2]) node2 = p[node2];
                    
                    if(node1 != node2)
                    {
                        result--; 
                        p[node1] = node2;
                    }
                }
        
        return result;
    }
};