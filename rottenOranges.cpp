#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshorange = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                if (grid[i][j] == 1) {
                    freshorange++;
                }
            }
        }
        int tm = 0;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        int cnt = 0;
        while (!q.empty()) {
            int currrow = q.front().first.first;
            int currcol = q.front().first.second;
            int currtime = q.front().second;
            tm = max(tm, currtime);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = currrow + delrow[i];
                int ncol = currcol + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    q.push({{nrow, ncol}, currtime + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != freshorange) {
            return -1;
        } else
            return tm;
    }
};