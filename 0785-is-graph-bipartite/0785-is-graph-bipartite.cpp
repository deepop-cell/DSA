class Solution {
public:
bool dfs(int node, vector<vector<int>>&adj,int col,vector<int>&colour){
    colour[node]=col;
    for(auto &v:adj[node]){
        if(colour[v]==col){
            //col same ho gya 
            return false;
        }
        else if(colour[v]==-1){
            if(dfs(v,adj,1-col,colour)==false){
                return false;
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int  n=graph.size();
        vector<vector<int>>adj(n);
        for(int u=0;u<n;u++){
            int a=u;
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i];
                adj[a].push_back(v);
                adj[v].push_back(a);
            }
        }
        vector<int>colour(n,-1);
        for(int u=0;u<n;u++){
            if(colour[u]!=-1){
                continue;//already coloured hai .
            }
          if(!dfs(u,adj,1,colour)){
            return false;
          }
        }
        return true;
    }
};