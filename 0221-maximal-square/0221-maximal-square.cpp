class Solution {
public:
int dp[301][301];
    int solve(int i,int j , vector<vector<char>>&g){
        if( i>=g.size() || j>=g[0].size()|| g[i][j]=='0'){
            return 0;
        }
        //we have option to extend in 3 dir .
        if(dp[i][j]!=-1){
            return dp[i][j];
        } 
        int r=solve(i,j+1,g);
        int d=solve(i+1,j,g);
        int diag=solve(i+1,j+1,g);
        return dp[i][j]=1 + min({r,d,diag});
    }
    int maximalSquare(vector<vector<char>>& g) {
        int mxside=-1;
                    memset(dp,-1,sizeof(dp));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='1'){
                    int y=solve(i,j,g);
                    mxside=max(mxside,y);
                }
            }
        }
        if(mxside==-1){
            return 0;
        }
        return 1LL*mxside * mxside;
    }
};