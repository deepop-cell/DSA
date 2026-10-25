class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<bool>>&vis,bool &f){
        vis[r][c]=true;
    if(r==grid.size()-1 || r==0 || c==grid[0].size()-1 || c==0){
     f=false;
    }
    for(auto &dir:directions){
        int newx=r+dir[0];
        int newy=c+dir[1];
        if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size() || grid[newx][newy]==1 || vis[newx][newy]){
            continue;
        }
        else{
            dfs(newx,newy,grid,vis,f);
        }
    }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    bool f=true;
                    dfs(i,j,grid,vis,f);
                    if(f)cnt++;
                }
            }
        }
        return cnt;
        
    }
};