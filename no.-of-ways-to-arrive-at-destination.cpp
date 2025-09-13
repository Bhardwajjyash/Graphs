#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        const long long INF = (long long)1e18;
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        //{dist,node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        vector<long long> dist(n, INF);
        dist[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        int mod = (int)(1e9 + 7);
        while (!pq.empty()) {
            auto it = pq.top();
            long long dis = it.first;
            int node = it.second;
            pq.pop();
            if (dis > dist[node])
                continue;
            for (auto iter : adj[node]) {
                long long edjwt = iter.second;
                int adjnode = iter.first;
                long long nd = dis + edjwt;
                // this is the first time i am coming with the short distance
                if (nd < dist[adjnode]) {
                    dist[adjnode] = nd;
                    pq.push({nd, adjnode});
                    ways[adjnode] = ways[node];
                } else if (nd == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return (int)ways[n - 1] % mod;
    }
};