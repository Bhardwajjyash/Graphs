#include<bits/stdc++.h>
using namespace std;



class DisjointSet {
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
private:
    bool isvalid(int nrow, int rcol, int n) {
        return nrow >= 0 && nrow < n && rcol >= 0 && rcol < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        // step 1;
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int nrow = i + dr[ind];
                    int ncol = j + dc[ind];
                    if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNO = i * n + j;
                        int adjnodeno = nrow * n + ncol;
                        ds.unionBySize(nodeNO, adjnodeno);
                    }
                }
            }
        }
        // step 2;
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];
                    if (isvalid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        components.insert(ds.findUPar(nrow * n + ncol));
                    }
                }
                int sizetotal = 0;
                for (auto it : components) {
                    sizetotal += ds.size[it];
                }
                mx = max(mx, sizetotal + 1);
            }
        }
        for (int cellno = 0; cellno < n; cellno++) {
            mx = max(mx, ds.size[ds.findUPar(cellno)]);
        }
        return mx;
    }
};