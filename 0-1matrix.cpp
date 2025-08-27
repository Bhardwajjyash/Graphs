#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] =1;
                } 
            }
        }
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        while (!q.empty()) {
            int currrow = q.front().first.first;
            int currcol = q.front().first.second;
            int sd = q.front().second;
            q.pop();
            ans[currrow][currcol] = sd;
            for (int d = 0; d < 4; d++) {
                int nrow = currrow + delrow[d];
                int ncol = currcol + delcol[d];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                    if (vis[nrow][ncol] == 0) {
                        vis[nrow][ncol] = 1;
                        q.push({{nrow , ncol},sd+1});
                    }
                }
            }
        }

        return ans;
    }
};