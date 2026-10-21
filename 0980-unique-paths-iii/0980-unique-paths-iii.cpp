class Solution {
public:
    int solve(int i, int j , vector<vector<int>>&grid,int endx,int endy,vector<vector<bool>>&vis,int cnt){
        if(  grid[i][j]==-1){
            return 0;
        }
        if(i==endx && j==endy && cnt==0){
            return 1;
        }
        //now we have 4 options and hence we need to keep a mark of vis to avoid cycling hence backtracking lagagei 
        int option1=0;
        int option2=0;
        int option3=0;
        int option4=0;
        if(i+1<grid.size() && !vis[i+1][j] ){
            vis[i+1][j]=true;
            if(grid[i+1][j]==0){
            option1=solve(i+1,j,grid,endx,endy,vis,cnt-1);
            }
            else{
            option1=solve(i+1,j,grid,endx,endy,vis,cnt);
            }
            vis[i+1][j]=false;//backtrakcing 
        }
        if(j+1<grid[0].size() && !vis[i][j+1] ){
            vis[i][j+1]=true;
            if(grid[i][j+1]==0){
            option2=solve(i,j+1,grid,endx,endy,vis,cnt-1);
            }
            else{
            option2=solve(i,j+1,grid,endx,endy,vis,cnt);
            }
            vis[i][j+1]=false;
        }
        if(i>0 && !vis[i-1][j] ){
            vis[i-1][j]=true;
            if(grid[i-1][j]==0){
            option3=solve(i-1,j,grid,endx,endy,vis,cnt-1);
            }
            else{
            option3=solve(i-1,j,grid,endx,endy,vis,cnt);
            }
            vis[i-1][j]=false;
        }
        if(j>0 && !vis[i][j-1]  ){
            vis[i][j-1]=true;
            if(grid[i][j-1]==0){
            option4=solve(i,j-1,grid,endx,endy,vis,cnt-1);
            }
            else{
            option4=solve(i,j-1,grid,endx,endy,vis,cnt);
            }
            vis[i][j-1]=false;
        }
        return option1+option2+option3+option4;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int startx=-1;
        int starty=-1;
        int endx=-1;
        int endy=-1;
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
                 if(grid[i][j]==2){
                    endx=i;
                    endy=j;
                }
                if(grid[i][j]==0){
                    cnt++;
                }
            }
        }
        vis[startx][starty]=true;
        return solve(startx,starty,grid,endx,endy,vis,cnt);
    }
};