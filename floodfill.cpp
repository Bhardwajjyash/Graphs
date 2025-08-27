#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& image, int color,
             vector<vector<int>>& ans, int initialColor) {
        int m = image.size();
        int n = image[0].size();
        int currrow = sr;
        int currcol = sc;
        ans[currrow][currcol] = color;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = currrow - delrow[i];
            int ncol = currcol - delcol[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                image[nrow][ncol] == initialColor && ans[nrow][ncol] != color) {
                ans[nrow][ncol] = color;
                dfs(nrow, ncol, image, color, ans, initialColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;

        dfs(sr, sc, image, color, ans, initialColor);
        return ans;
    }
};

// nrow = neighbour row
// ncol = neighbour col
// delrow  = delta(change)in row
// delcol  = delta(change)in col