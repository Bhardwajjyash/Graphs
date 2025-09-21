#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool isvalid(int r, int c, int n, int m)
{
    return (r >= 0 && r < n && c >= 0 && c < m);
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    DisjointSet ds(n * m);
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    vector<int> ans;
    for (auto it : q)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] = 1;
        cnt++;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int ind = 0; ind < 4; ind++)
        {
            int nrow = row + dr[ind];
            int ncol = col + dc[ind];
            if (isvalid(nrow, ncol, n, m))
            {
                if (vis[nrow][ncol] == 1)
                {
                    int nodeno = row * m + col;
                    int adjnodeno = nrow * m + ncol;
                    if (ds.findUPar(nodeno) != ds.findUPar(adjnodeno))
                    {
                        cnt--;
                        ds.unionByRank(nodeno, adjnodeno);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}