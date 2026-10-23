class Solution {
public:
long long dp[201][201];
     int solve(int i,int j,vector<vector<int>>&grid){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //now we have 2 opitions to explore.
        int option1=solve(i,j+1,grid);
        int option2=solve(i+1,j,grid);
        return  dp[i][j]=grid[i][j]+min(option1,option2);
     }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp)); 
        return solve(0,0,grid);
    }
};