#include<bits/stdc++.h>
using namespace std;


class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis,
             vector<int>& check, vector<vector<int>>& graph) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        // traverse for adjacent node
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathvis, check, graph) == true) {
                    // means cycle found so dont include in safenode
                    check[node] = 0;
                    return true;
                }
            }
            if (pathvis[it]) {
                // means on same path we found the same element again
                check[node] = 0;
                return true;
            }
        }
        // means no cycle found so its a safe node
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> check(n, 0);
        vector<int> safenode;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, pathvis, check, graph);
            }
        }
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};