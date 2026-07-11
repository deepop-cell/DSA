class Solution {
public:
void dfs(int node,vector<bool>&vis,vector<vector<int>>&adj,int &vertexcount,int&edgecount){
    vis[node]=true;
    vertexcount++;
    edgecount+=adj[node].size();
    for(auto &nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,adj,vertexcount,edgecount);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
    int ans=0;
    vector<vector<int>>adj(n);
    vector<bool>vis(n,false);
    for(auto &e:edges){
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // see for complete componenets , n nodes ke beech har pair mai ek edge hona chaiye so nc2 edges hone chahie. agar degrees se edge count kaarein to wo 2* actual edgecount ata hai.. so simply equate kro ,, n*n-1/2=total degree /2. 
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int vertexcount=0;
            int edgecount=0;
            dfs(i,vis,adj,vertexcount,edgecount);
            if(edgecount==vertexcount *(vertexcount-1)){
                ans++;
            }
        }
    }
    return ans;
    }
};