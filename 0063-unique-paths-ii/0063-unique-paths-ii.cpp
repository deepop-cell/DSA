class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=1;
        //state def: dp[i][j]=no of ways of reaching i , j from source (0,0)..
                //filling the first row...
                for(int col=0;col<n;col++){
                    if( col>=1 && obstacleGrid[0][col-1]==1){
                        dp[0][col]=0;
                        obstacleGrid[0][col]=1;//for future lements of this column
                    }
                    else if(obstacleGrid[0][col]==1){
                        dp[0][col]=0;
                    }
                    else{
                        dp[0][col]=1;
                    }
                }
                //filling the first col.
                for(int row=0;row<m;row++){
                    if(row>=1 && obstacleGrid[row-1][0]==1){
                        dp[row][0]=0;
                        obstacleGrid[row][0]=1;
                    }
                    else if(obstacleGrid[row][0]==1){
                        dp[row][0]=0;
                    }
                    else{
                        dp[row][0]=1;
                    }
                }
                //ab baki ko bhar do..
                for(int i=1;i<m;i++){
                    for(int j=1;j<n;j++){
                        if(obstacleGrid[i][j]==1){
                            dp[i][j]=0;
                    }
                        else{
                            dp[i][j]=dp[i-1][j]+dp[i][j-1];
                        }
                    }
                }
            
        
        return dp[m-1][n-1];
    }
};