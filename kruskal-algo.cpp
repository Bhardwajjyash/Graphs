#include<bits/stdc++.h>
using namespace std;


// User function Template for C++
class DisjointSet {
    vector<int> rank, parent,size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        vector<pair<int,pair<int,int>>> list;
            for(auto it : edges){
                int adjnode = it[1];
                int wt = it[2];
                int node = it[0];
                list.push_back({wt,{node,adjnode}});
            }
        
        sort(list.begin(),list.end());
        int mswt = 0;
        DisjointSet ds(V);
        for(auto it : list){
            int wt = it.first;
            int u = it.second.first;
            int v= it.second.second;
        
        if(ds.findUPar(u) != ds.findUPar(v)){
            mswt+=wt;
             ds.unionByRank(u,v);
        }        
        
       }
        return mswt;
    }
};