class Solution {
public:
int dp[201][201];
int solve(int i,int j,int m,int n,vector<vector<int>>&matrix){
    if(i<0 || i>=m || j<0 || j>=n){
        return -1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int o1=1;
    int o2=1;
    int o3=1;
    int o4=1;
    //base case is ki agar ab kahi move nhi kr skte ho to return 0 kr jao.
    if( ( i==0 || matrix[i][j]>matrix[i-1][j]) && (i+1>=m || matrix[i+1][j]<matrix[i][j]) && (j==0 || matrix[i][j]>matrix[i][j-1]) && (j+1>=n || matrix[i][j]>matrix[i][j+1])){
        //this means now all paths are blocked.
        return 1;//ye jo curr hai ye to ek add krega na path lentgh mai
    }
    if( j+1<n && matrix[i][j+1]>matrix[i][j]){
        o1=1+solve(i,j+1,m,n,matrix);
    }
    if( i+1<m && matrix[i+1][j]>matrix[i][j]){
        o2=1+solve(i+1,j,m,n,matrix);
    }
    if( j>0 && matrix[i][j-1]>matrix[i][j]){
        o3=1+solve(i,j-1,m,n,matrix);
    }
    if( i>0 && matrix[i-1][j]>matrix[i][j]){
        o4=1+solve(i-1,j,m,n,matrix);
    }
    return dp[i][j]=max({o1,o2,o3,o4});
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int maxans=INT_MIN;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //make starting point this,
                maxans=max(maxans,solve(i,j,m,n,matrix));
            }
        }
        return maxans;
    }
};