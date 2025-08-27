#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int i, int n, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : graph[node]) {
                // if adj node is not colored yet you have to color it with
                // opposite color
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                // if adj node is color and if it is same color then graph is
                // not bipartite
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (check(i, n, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};