class Solution {
public:
int dp[301][301];
    int solve(int i,int j,vector<vector<char>>&grid,int n,int m){
        if(i>=n || j>=m){
            return 0;
        }
        //now at curremt we can only extend if its 1.
        if(grid[i][j]=='0'){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //now options 
        int right=solve(i,j+1,grid,n,m);
        int down=solve(i+1,j,grid,n,m);
        int diag=solve(i+1,j+1,grid,n,m);
        return  dp[i][j]=1+min({right,down,diag});
    }
    int maximalSquare(vector<vector<char>>&grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxside=INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    int x=solve(i,j,grid,n,m);
                    maxside=max(maxside,x);
                }
            }
        }
        if(maxside==INT_MIN){
            return 0;
        }
        long long area=1LL*(maxside)*(maxside);
        return area;
    }
};