class Solution {
public:
    vector<int> dfs(int node, vector<vector<int>>&adj,vector<int>&ans,string & labels,vector<bool>&vis){
        vector<int>a(26,0);
        a[labels[node]-'a']++;
        vis[node]=true;
        for(auto &v:adj[node]){
            if(vis[v])continue;
            vector<int>x=dfs(v,adj,ans,labels,vis);
            for(int i=0;i<26;i++){
                a[i]+=x[i];
            }
        }
        ans[node]=a[labels[node]-'a'];
        return a;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>>adj(n);
        for(auto &edge:edges){
            int a=edge[0];
            int b=edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>vis(n,false);
        vector<int>ans(n,0);
        dfs(0,adj,ans,labels,vis);
        return ans;
    }
};