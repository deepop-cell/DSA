class Solution {
public:
void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,vector<int>&x){
    vis[node]=true;
    for(auto &v:adj[node]){
        if(vis[v]){
            continue;
        }
            x.push_back(v);
            dfs(v,vis,adj,x);
    }
}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        //this will store edges in reversed order.
        for(auto &edge:edges){
            int a=edge[0];
            int b=edge[1];
            //og graph is a-->b.
            //rev is b-->a.
            adj[b].push_back(a);
        }
        //now from each node do dfs.
        vector<vector<int>>ans;
        for(int u=0;u<n;u++){
            vector<int>ancestors;
        vector<bool>vis(n,false);
            dfs(u,vis,adj,ancestors);
            sort(ancestors.begin(),ancestors.end());
            ans.push_back(ancestors);
        }
        return ans;
    }
};