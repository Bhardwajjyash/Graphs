#include<bits/stdc++.h>
using namespace std;

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int,int>>> adj(V);
        for(int i = 0 ; i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});

        }
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({src,0});
        while(!pq.empty()){
            int node = pq.top().first;
            int distance = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgeweight = it.second;
                if(dist[node] != INT_MAX && distance + edgeweight < dist[adjnode]){
                    dist[adjnode] = distance + edgeweight;
                    pq.push({adjnode,dist[adjnode]});
                }
            }
        }
        return dist;
    }
};