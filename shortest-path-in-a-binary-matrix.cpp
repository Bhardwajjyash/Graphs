#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        pair<int, int> start = {0, 0};
        pair<int, int> end = {n - 1, n - 1};
        q.push({1, {start.first, start.second}});
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        int delrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n-1 && c == n-1) return dis;

            for (int i = 0; i < 8; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = 1 + dis;
                    if (nrow == end.first && ncol == end.second)
                        return dis + 1;
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};