class Solution {
public: 
long long dp[501][501][3];
int mod=1e9+7;
    long long solve(int i , int j , vector<vector<int>>&grid,int dir){
        //dir means 1/2 (1 meand yahapar right marke aaae ho 2 means down marke aaye ho )
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return 0;
        }
        //now we have two options . 
        //right ya to down
        if(dp[i][j][dir]!=-1){
            return dp[i][j][dir];
        }
        if(grid[i][j]==1){
            if(dir==1){
                //means right maarke aaaya hu yaha to donw hee jaunga 
                return dp[i][j][dir]=solve(i+1,j,grid,2);
            }
            else{
                //means down marke aaya hu to right jaunga 
                return  dp[i][j][dir]=solve(i,j+1,grid,1);
            }
        }
        long long right=solve(i,j+1,grid,1);
        long long down=solve(i+1,j,grid,2);
        
        return dp[i][j][dir]=(right+down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int dir=0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,grid,dir);
    }
};