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
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n+1);
        for(auto &edges:invocations){
            int u=edges[0];
            int v=edges[1];
            adj[u].push_back(v);//u----->v edge hai . directed hai 
        }
        vector<bool>vis(n,false);
        dfs(k,adj,vis);
        bool candelete=true;
        for(auto &edges:invocations){
            int u=edges[0];
            int v=edges[1];
            if((vis[u] && !vis[v])||(vis[v] && !vis[u])){
                candelete=false;
                break;
            }
        }
        vector<int>ans;
        if(!candelete){
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};