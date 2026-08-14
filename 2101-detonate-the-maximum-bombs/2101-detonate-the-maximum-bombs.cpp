class Solution {
public:
void dfs(int node, vector<bool>&vis,vector<vector<int>>&adj,int &count){
    vis[node]=true;
    count++;
    for(auto &v:adj[node]){
        if(!vis[v]){
            dfs(v,vis,adj,count);
        }
    }
}
bool inside(int x1,int y1, int x2,int y2,int r1,int r2){
    long long dx=(x2-x1);
    long long dy=(y2-y1);
    return (1LL*(dx*dx) + 1LL*(dy*dy)<=1LL*r1*r1);
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
                int x1=bombs[i][0];
                int y1=bombs[i][1];
                int r1=bombs[i][2];
            for(int j=0;j<n;j++){
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                int r2=bombs[j][2];
                if(inside(x1,y1,x2,y2,r1,r2)){
                    //this is a neighbour.
                    adj[i].push_back(j);
                }
            }
        }
        int ans=-1;
        vector<bool>vis(n,false);
        //now just start dfs from node form allnodes and keep a ciunter of number of nodes vis.
        for(int i=0;i<n;i++){
            fill(vis.begin(),vis.end(),false);
            int x=0;
            dfs(i,vis,adj,x);
            ans=max(ans,x);
        }
        return ans;
    }
};