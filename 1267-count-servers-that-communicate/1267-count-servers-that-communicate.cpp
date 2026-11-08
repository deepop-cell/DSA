class Solution {
public:
    void dfs(int r,int c,vector<vector<bool>>&vis,vector<vector<int>>&grid,int n,int m,int &count){
        vis[r][c]=true;
        count++;
        for(int j=0;j<m;j++){
            if(grid[r][j]==1 && !vis[r][j]){
                dfs(r,j,vis,grid,n,m,count);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][c]==1 && !vis[i][c]){
                dfs(i,c,vis,grid,n,m,count);
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int count=0;
                    dfs(i,j,vis,grid,n,m,count);
                    if(count>1){
                    ans+=count;
                    }

                }
            }
        }
        return ans;
        
    }
};