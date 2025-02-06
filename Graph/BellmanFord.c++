#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> ans(V , 1e8);
        ans[src] = 0;
        
        for(int i = 1 ; i <= V - 1 ; i++) {
            
            for(auto& it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                
                if(ans[u] != 1e8 && ans[u] + w < ans[v]) {
                    ans[v] = ans[u] + w;
                } 
            }
        }
        
        for(auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(ans[u] != 1e8 && ans[u] + w < ans[v]) {
                return {-1}; // agar v - 1 ke baad ek bhi baar aur update hua to matlab negative cycle present hai
            } 
        }
        
        return ans;
    }
};

int main() {
 // 
}