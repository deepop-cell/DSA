class Solution {
public:
int dp[101][101];
bool vis[101][101];
    int solve(int i,int j,vector<vector<int>>&matrix,int n){
        if(i>=n || j<0 || j>=n){
            return 1e9;
        }
        if(i==n-1 ){
            //manzil yani last row aa gai hai.
            return matrix[i][j];
        }
        if(vis[i][j]){
            return dp[i][j];
        }
        //ab we have 3 options
        int p1=solve(i+1,j,matrix,n);
        int p2=solve(i+1,j+1,matrix,n);
        int p3=solve(i+1,j-1,matrix,n);
        vis[i][j]=true;
        return  dp[i][j]=min({p1,p2,p3})+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            int x=solve(0,j,matrix,n);
            ans=min(ans,x);
        }
        return ans;
    }
};