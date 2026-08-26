class Solution {
public:
int dp[201][201];
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i>=grid.size() || j>=grid[0].size()){
            return 1e9;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //now here we have two opiotns ya to down ya to right
        int right=solve(i,j+1,grid);
        int down=solve(i+1,j,grid);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid);
    }
};