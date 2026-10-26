class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c, vector<vector<int>>&grid,long long &sum){
        sum+=grid[r][c];
        grid[r][c]=0;//marking vis.
        for(auto &dir:directions){
            int newr=r+dir[0];
            int newc=c+dir[1];
            if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size() || grid[newr][newc]==0){
                continue;
            }
            else{
                dfs(newr,newc,grid,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
    int cnt=0;
    int m=grid.size();
    int n=grid[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=0){
                long long sum=0;
                dfs(i,j,grid,sum);
                if(sum%k==0){
                    cnt++;
                }
            }
        }
    }
    return cnt;
    }
};