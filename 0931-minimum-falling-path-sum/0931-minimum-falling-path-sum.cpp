class Solution {
public:
int dp[101][101];
bool vis[101][101];
    int solve(int i,int j,vector<vector<int>>& matrix,int n){
        if(i>=n || j>=n || j<0){
            return 1e9;
        }
        if(i==n-1){
            //destination reached
            return matrix[i][j];
        }
        if(vis[i][j]){
            return dp[i][j];///if already visisted then return the value 
        }
        //ab dekho .
        int down=solve(i+1,j,matrix,n);
        int leftdown=solve(i+1,j-1,matrix,n);
        int rightdown=solve(i+1,j+1,matrix,n);
        vis[i][j]=true;
        return  dp[i][j]=matrix[i][j]+min({down,leftdown,rightdown});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //so try starting from every top row as a start. since constraints are smaller we can do it..
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int ans=INT_MAX;
        int n=matrix.size();
        for(int j=0;j<n;j++){
            int x=solve(0,j,matrix,n);
            ans=min(ans,x);
        }
        return ans;
    }
};
//see using dp[i][j]!=-1 fails in this problem because min path sum -1 bhi ho skta hai isliye we will use a seprate vis array too in this questimn