#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
bool dfscheck(int node , vector<int> adj[] , vector<int> &vis,vector<int> &pathvis){
      vis[node] = 1;
      pathvis[node] = 1;
      for(auto it : adj[node]){
          if(!vis[it]){
              if(dfscheck(it,adj,vis,pathvis) == true) return true;
          }
          else if(pathvis[it]) return true;
      }
      pathvis[node] = 0;
      return false;
  }
public:
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int> vis (N,0);
        vector<int> pathvis(N,0);
        for(int i = 0 ; i < N ; i++){
            if(!vis[i]){
                if(dfscheck(i,adj,vis,pathvis)==true) return true;
            }
        }
        return false;
    }
};
