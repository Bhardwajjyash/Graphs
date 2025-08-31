#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  private:
  void dfstopo(int i ,vector<vector<pair<int,int>>>& adj,vector<bool>& vis,stack<int>& st){
      vis[i] = true;
      for(auto it : adj[i]){
          int v  = it.first;
          if(vis[v] == false){
              dfstopo(v,adj,vis,st);
          }
      }
      st.push(i);
  }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0 ; i  < E ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        } 
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i = 0 ; i < V ; i++){
            if(vis[i]==false){
                dfstopo(i,adj,vis,st);
            }
        }
        //find distance
        vector<int> dist(V,INT_MAX);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                int v  = it.first;
                int wt = it.second;
                if(dist[node] != INT_MAX&&dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
            
        }
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
