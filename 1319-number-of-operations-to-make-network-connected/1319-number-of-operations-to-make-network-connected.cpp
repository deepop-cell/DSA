class Solution {
public:
        void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
            vis[node]=true;
            for(auto &v:adj[node]){
                if(!vis[v]){
                    dfs(v,adj,vis);
                }
            }
        }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int x=connections.size();
        vector<bool>vis(n,false);
        if(x<n-1){
            return -1;
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<x;i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);//undirected graph.u--v
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,adj,vis);
            }

        }
        return c-1;
        
    }
};