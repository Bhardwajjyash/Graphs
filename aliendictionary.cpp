#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_set<char> st;
        for (auto &w : words) {
            for (char c : w) st.insert(c);
        }
        int v = st.size();
        vector<vector<int>> adj(26);
        for(int i = 0 ; i  < n-1 ; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int len = min(w1.size(),w2.size());
            for(int j = 0 ; j < len ; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
               else if (j == len-1 && w1.size() > w2.size()) {
                    // invalid case: "abc" before "ab"
                     return "";
    }
            }
        }
        
        vector<int> indegree(26,0);
        for(int i = 0 ; i  < adj.size();i++){
            for(auto it:adj[i]){
            indegree[it]++;
            }
        }
        queue<int> q;
        for(char c : st) {
            if(indegree[c-'a'] == 0) {
                q.push(c-'a');
        }
    }

        int cnt = 0;
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        string ans = "";
        if(cnt == v){
            for(auto it : topo){
                ans = ans + char(it+'a');
            }
        }
        return ans;
        
    }
};