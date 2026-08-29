class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<int>&currgrp,vector<vector<int>>&adj){
        vis[node]=true;
        currgrp.push_back(node);
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs(v,vis,currgrp,adj);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<vector<int>>groups;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>currgrp;
                dfs(i,vis,currgrp,adj);
                groups.push_back(currgrp);
            }
        }
        long long ans=0;
        for(auto &x:groups){
            int currsize=x.size();
            ans+=1LL*(currsize)*(n-currsize);
        }
        return ans/2;
    }
};