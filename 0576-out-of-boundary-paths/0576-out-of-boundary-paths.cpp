class Solution {
public:
int MOD=1e9+7;
int dp[51][51][51];
    int solve(int i,int j,int m,int n,int moves){
        if(i<0 || j<0 || i>=m || j>=n){
            //we have found a path for outwards.
            return 1;
        }
        if(moves==0){
            return 0;
        }
        if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        //now we have 4 options.
        long long ways=0;
        ways+=solve(i+1,j,m,n,moves-1);
        ways+=solve(i,j+1,m,n,moves-1);
        ways+=solve(i-1,j,m,n,moves-1);
        ways+=solve(i,j-1,m,n,moves-1);
        return dp[i][j][moves]=ways%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,m,n,maxMove);
        
    }
};