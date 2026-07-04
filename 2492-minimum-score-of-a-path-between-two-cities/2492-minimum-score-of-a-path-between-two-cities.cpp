class Solution {
public:
void dfs(int node,vector<vector<vector<int>>>& adj,vector<bool>&vis,int &score ){
    vis[node]=true;
    for(auto &temp:adj[node]){
        int v=temp[0];
        int wt=temp[1];
        score=min(score,wt);
        if(!vis[v]){
        dfs(v,adj,vis,score);
        }
        
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        //pehle adjacnecy list bana lenge
        vector<vector<vector<int>>> adj(n + 1);
        for(auto &e:roads){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<bool>vis(n+1,false);
        int score=INT_MAX;
        dfs(1,adj,vis,score);
        return score;
    }
};