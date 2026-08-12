class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,int&count){
        vis[node]=true;
        count++;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis,count);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        for(auto &x:restricted){
            vis[x]=true;//mark the restricted nodes as already visisted.
        }
        int totalcount=0;
        dfs(0,adj,vis,totalcount);
        return totalcount;
    }
};