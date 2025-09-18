#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(int   i = 0; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            
        }
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        //{wt,node}
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            if(vis[node] != 0)continue;
            vis[node] = 1;
            sum += wt;
            for(auto iter : adj[node]){
                int adjnode = iter.first;
                int ewt = iter.second;
                if(vis[adjnode]==0){
                    pq.push({ewt,adjnode});
                }
            }
        }
        return sum;
        
    }
};