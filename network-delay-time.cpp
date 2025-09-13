#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[0]= 0;//as nodes are from 1 to n
        dist[k] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            int time = it.first;
            int node = it.second;
            pq.pop();
            for (auto iter : adj[node]) {
                int adjnode = iter.first;
                int time_to_reach = iter.second;
                if (time + time_to_reach < dist[adjnode]) {
                    dist[adjnode] = time + time_to_reach;
                    pq.push({time + time_to_reach, adjnode});
                }
            }
        }
        int ans = 0;
        for (auto it : dist) {
            if(it == 1e9)
                return -1;
            ans = max(ans, it);
        }
        return ans;
    }
};