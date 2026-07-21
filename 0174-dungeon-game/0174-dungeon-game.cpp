class Solution {
public:
int dp[201][201];
int solve(int i,int j,int n,int m,vector<vector<int>>&dungeon){
        if(i>=m || j>=n){
            return INT_MAX;//so that it gets ignored by min function
        }
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]>0){
                return 1;//wo waise b health badha dega to 1 hee dedo 
            }
            else{
                return 1+abs(dungeon[i][j]);
            }
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solve(i,j+1,n,m,dungeon);
        int down=solve(i+1,j,n,m,dungeon);
        int res=min(right,down)-dungeon[i][j];
        return dp[i][j]=(res>0)?res:1;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        int m=dungeon.size();
        int n=dungeon[0].size();
        return solve(0,0,n,m,dungeon);
        
    }
};