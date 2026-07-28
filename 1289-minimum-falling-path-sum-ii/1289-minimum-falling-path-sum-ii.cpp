class Solution {
public:
int dp[201][201];
bool vis[201][201];
    int solve(int i,int j,vector<vector<int>>&grid,int n){
        if(i>=n ){
            return 1e9;
        }
        if(i==n-1){
            return grid[i][j];
        }
        if(vis[i][j]){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=0;k<n;k++){
            if(k==j){
                //same col
                continue;
            }
            int y=solve(i+1,k,grid,n);
            ans=min(ans,y);
        }
        vis[i][j]=true;
        return  dp[i][j]=ans+grid[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int res=INT_MAX;
        int n=grid.size();
        for(int j=0;j<n;j++){
            int x=solve(0,j,grid,n);
            res=min(res,x);
        }
        return res;
    }
};