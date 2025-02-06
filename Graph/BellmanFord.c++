#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int v , int e, int source) {
    // Write your code here.
    unordered_map<int , vector<pair<int,int>>> adj;
    for(int i = 0 ; i < e ; i++) {      
      int u = vec[i][0];
      int v = vec[i][1];
      int w = vec[i][2];

      adj[u].push_back({v , w});
      adj[v].push_back({u , w});
    }

    vector<int> ans(v , INT_MAX);
    set<pair<int , int>> st;
    st.insert({0 , source});
    ans[source] = 0;

    while(!st.empty()) {
        auto& it = *st.begin();
        int d = it.first;
        int node = it.second;
        st.erase(it);

        for(auto& neighbour : adj[node]) {
            int adjnode = neighbour.first;
            int wt = neighbour.second;

            if(d + wt < ans[adjnode]) {

                if(ans[adjnode] != INT_MAX) { // jo exist karta hai usko hata do kyuki usse chota mil chuka hai
                    st.erase({ans[adjnode] , adjnode});
                }

                st.insert({d + wt , adjnode});
                ans[adjnode] = d + wt;
            }
        }
    }
    return ans;
}

int main() {
 // 
}