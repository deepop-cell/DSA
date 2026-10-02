class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int r,int c,long long &sum,vector<vector<int>>& grid){
        sum+=grid[r][c];
        grid[r][c]=0;///vis mark kr rha hu
        for(auto &dir:directions){
            int newr=r+dir[0];
            int newc=c+dir[1];
            if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size() || grid[newr][newc]==0){
               continue;
            }
             dfs(newr,newc,sum,grid);
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    long long sum=0;
                    dfs(i,j,sum,grid);
                    //now check if sum is disivble by k
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};