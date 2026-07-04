class Solution {
public:
bool dfs(int currnode,vector<int>&color,int currcolor,vector<vector<int>>& adj){
    color[currnode]=currcolor;
    for(auto &v:adj[currnode]){
        if(color[v]==-1){
            if(dfs(v,color,1-currcolor,adj)==false){
                return false;
            }
        }
        else if(color[v]==currcolor){
                return false;
            }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        vector<int>color(n+1,-1);
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }//adjancency list banalo
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
            if(!dfs(i,color,1,adj)){
                return false;
            }
            }
        }
        return true;
    }
};