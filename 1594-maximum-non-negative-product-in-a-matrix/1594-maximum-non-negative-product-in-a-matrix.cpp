class Solution {
public:
typedef long long ll;
ll MOD=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //state de. dp[i][j]={maxval,minval}, ggives max and min product from 0 to (i,j)..
        vector<vector<pair<ll,ll>>>dp(m,vector<pair<ll,ll>>(n));
        dp[0][0]={grid[0][0],grid[0][0]};
        for(int col=1;col<n;col++){
            ll leftmax=dp[0][col-1].first;
            ll leftmin=dp[0][col-1].second;
            dp[0][col].first=max(grid[0][col]*leftmax,grid[0][col]*leftmin);
            dp[0][col].second=max(grid[0][col]*leftmax,grid[0][col]*leftmin);
        }
        for(int i=1;i<m;i++){
            ll upmax=dp[i-1][0].first;
            ll upmin=dp[i-1][0].second;
            dp[i][0].first=max(grid[i][0]*upmax,grid[i][0]*upmin);
            dp[i][0].second=min(grid[i][0]*upmax,grid[i][0]*upmin);
        }
        //first col and row bhargya hai,... ab aage bharop..
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //manlo yaha se left se aya hu..
                ll leftmax=dp[i][j-1].first;
                ll leftmin=dp[i][j-1].second;
                //manlo up se yaha aaya hu..
                ll upmax=dp[i-1][j].first;
                ll upmin=dp[i-1][j].second;
                dp[i][j].first=max({grid[i][j]*leftmax,grid[i][j]*leftmin,grid[i][j]*upmax,grid[i][j]*upmin});
                dp[i][j].second=min({leftmax*grid[i][j],leftmin*grid[i][j],grid[i][j]*upmax,grid[i][j]*upmin});
            }
        }
    ll maxval=dp[m-1][n-1].first;
    return (maxval<0)? -1:maxval%MOD;
        
    }
};