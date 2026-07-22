class Solution {
public:
int dp[501][501][3];
    int solve(int i,int j,int k,vector<vector<int>>&coins){
        if(i>=coins.size() || j>=coins[0].size()){
            return -1e9;//so that max fucntion ignores it.
        }
        if(i==coins.size()-1 && j==coins[0].size()-1){
            if(coins[i][j]<0 && k>0){
                return 0;//used the potion
            }
            return coins[i][j];
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int use=0;
        int skip=0;
        if(coins[i][j]<0 && k>0){
            use=max(solve(i+1,j,k-1,coins),solve(i,j+1,k-1,coins));
            skip=coins[i][j]+max(solve(i+1,j,k,coins),solve(i,j+1,k,coins));
            return dp[i][j][k]= max(skip,use);
        }
            int right=coins[i][j]+solve(i,j+1,k,coins);
            int down=coins[i][j]+solve(i+1,j,k,coins);
            return dp[i][j][k]= max(right,down);
        

    }
    int maximumAmount(vector<vector<int>>& coins) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,2,coins);
        return ans;
    }
};