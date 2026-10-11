class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
   void dfs(int r,int c,long long &sum,vector<vector<int>>& grid){
    sum+=grid[r][c];
    grid[r][c]=0;//marking vis.
    for(auto &dir:directions){
        int nr=r+dir[0];
        int nc=c+dir[1];
        if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size() || grid[nr][nc]==0){
            continue;
        }
        dfs(nr,nc,sum,grid);
    }
   }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    //yaaha se start kr skte hai . 
                    long long sum=0;
                    dfs(i,j,sum,grid);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};