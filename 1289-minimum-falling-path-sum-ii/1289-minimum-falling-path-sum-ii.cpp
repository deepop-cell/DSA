class Solution {
public:
int dp[201][201];
bool vis[201][201];
    int solve(int i,int j,vector<vector<int>>&grid,int n){
        if(i>=n || j>=n || j<0){
            return 1e9;
        }
        if(i==n-1){
            //last row reached...
            return grid[i][j];
        }
        if(vis[i][j]){
            return dp[i][j];
        }
        //now chose min
        int minx=INT_MAX;
        for(int k=0;k<n;k++){
            if(k==j){
                continue;//skip this becasue same col
            }
            int y=solve(i+1,k,grid,n);
            minx=min(minx,y);
        }
        vis[i][j]=true;
        return dp[i][j]= grid[i][j]+minx;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int n=grid.size();
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            int x=solve(0,j,grid,n);
            ans=min(ans,x);
        }
        return ans;
    }
};