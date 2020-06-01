/*
On a 2D plane, we place stones at some integer coordinate points.  
Each coordinate point may have at most one stone.
Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
What is the largest possible number of moves we can make?
*/

// Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Approach: Union-Find

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    vector<int> p;
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); 
        
        p.resize(20000, 0);
        for(int i=0; i<p.size(); i++)
            p[i] = i; 
        
        for(auto stone: stones)
            _union(stone[0], stone[1]+10000); 
        
        unordered_set<int> seen;
        for(auto stone: stones)
            seen.insert(_find(stone[0]));
        
        return n-seen.size();
    }
    
    int _find(int x)
    {
        while(x != p[x]) x = p[x]; 
        return x;
    }
    
    void _union(int x, int y)
    {
        p[_find(x)] = _find(y);
    }
};

/*
Let's connect row i to column j, which will be represented by j+10000. 
The answer is the number of components after making all the connections.
*/