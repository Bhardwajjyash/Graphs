#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int i = it[0];
            int j = it[1];
            int p = it[2];
            adj[i].push_back({j, p});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty()) {
            auto it = q.front();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            q.pop();
            if (stops > k)
                continue;
            for (auto iter : adj[node]) {
                int adjnode = iter.first;
                int adjprice = iter.second;
                if (price + adjprice < dist[adjnode] && stops <= k) {
                    dist[adjnode] = price + adjprice;
                    q.push({stops + 1, {adjnode, price + adjprice}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};