class Solution {
public:  
    void dfs(int node,int &cnt,vector<vector<pair<int,int>>>&adj,vector<bool>&vis){
        vis[node]=true;
        for(auto &x:adj[node]){
            if(!vis[x.first]){
                if(x.second==1){
                    cnt++;
                }
                dfs(x.first,cnt,adj,vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &x:connections){
            int a=x[0];
            int b=x[1];
            //road is from a-->b.
            adj[a].push_back({b,1});//1 means forward directions
            adj[b].push_back({a,-1});//-1 means backward direction
        }
            int cnt=0;
            vector<bool>vis(n,false);
            dfs(0,cnt,adj,vis);
            return cnt;

    }
};