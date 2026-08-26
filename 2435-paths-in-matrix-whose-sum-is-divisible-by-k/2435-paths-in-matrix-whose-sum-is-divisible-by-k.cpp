class Solution {
public:
int n,m;
int mod=1e9+7;
vector<vector<vector<int>>>dp;
    int solve(int i,int j,int currsum , vector<vector<int>>&grid,int k){
        if(i>=n || j>=m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return (currsum + grid[i][j])%k==0;
        }
        if(dp[i][j][currsum]!=-1){
            return dp[i][j][currsum];
        }
        //we have options
        int next_sum=(currsum+grid[i][j])%k;
        int down=solve(i+1,j,next_sum,grid,k);
        int right=solve(i,j+1,next_sum,grid,k);
        return dp[i][j][currsum]=(down+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=grid[i][j]%k;
            }
        }
        return solve(0,0,0,grid,k);
    }
};