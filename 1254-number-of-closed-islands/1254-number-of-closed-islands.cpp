class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>& grid,int n,int m,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c]=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(x>0 && !vis[x-1][y] && grid[x-1][y]==0){
                    q.push({x-1,y});
                    vis[x-1][y]=true;
                }
                if(y>0 && !vis[x][y-1] && grid[x][y-1]==0){
                    q.push({x,y-1});
                    vis[x][y-1]=true;
                }
                if(x+1<n && !vis[x+1][y] && grid[x+1][y]==0){
                    q.push({x+1,y});
                    vis[x+1][y]=true;
                }
                if(y+1<m && !vis[x][y+1] && grid[x][y+1]==0){
                    q.push({x,y+1});
                    vis[x][y+1]=true;
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==n-1 || j==m-1 || i==0 || j==0)&& grid[i][j]==0){
                    vis[i][j]=true;
                    bfs(i,j,grid,n,m,vis);
                    //mark the boundary  ones as already marked.
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    count++;
                    bfs(i,j,grid,n,m,vis);
                }
            }
        }
        return count;
    }
};