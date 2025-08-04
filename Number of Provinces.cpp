class Solution {
    private:
    void vis(int k,vector<vector<int>>& adj,vector<int>& isvis){
        isvis[k]=1;
        for(auto it : adj[k]){
            if(isvis[it]==0){
                vis(it,adj,isvis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]==1 && i !=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int provinces = 0;
        vector<int> isvis(n,0);
        for (int k = 0; k < n; k++) {
           if(isvis[k]==0){
            provinces++;
            vis(k,adj,isvis);
           }
        }
        return provinces;
    }
};