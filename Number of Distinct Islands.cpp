// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void bfs(int row , int col , vector<vector<int>>& grid , vector<vector<int>>& vis,vector<pair<int,int>>& shape, int baseRow, int baseCol){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size(); 
         // 4-directional movement
        int dRow[] = {-1,1,0,0}; 
        int dCol[] = {0,0,-1,1};

        shape.push_back({0,0}); // Initial relative pos
        while(!q.empty()){
            int currrow = q.front().first;
            int currcol = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int nrow = currrow + dRow[k];
                int ncol = currcol + dCol[k];
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol <m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        vis[nrow][ncol] =1;
                        // record the shape as per the starting point
                        shape.push_back({nrow - baseRow, ncol - baseCol});
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>> shapes;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int row = 0;row<n;row++){
            for(int col = 0; col<m;col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    vector<pair<int, int>> shape;
                    bfs(row,col,grid,vis,shape, row, col);
                    sort(shape.begin(), shape.end()); // For set to work correctly
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
};