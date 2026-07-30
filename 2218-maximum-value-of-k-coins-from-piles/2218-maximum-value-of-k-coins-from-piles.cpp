class Solution {
public:
int dp[1001][2001];
    int solve(int i,vector<vector<int>>&piles,int k){
        if(i==piles.size()){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }

        //skip karo ye current pile.
        int nottake=solve(i+1,piles,k);
        //take current pile and tryt getting first 1,2,..k from current pile
        int sum=0;
        int maxres=0;
        int x=min((int)piles[i].size(),k);
        for(int j=0;j<x;j++){
            sum+=piles[i][j];
            int money=sum+solve(i+1,piles,k-(j+1));
            maxres=max(maxres,money);
        }
        return  dp[i][k]=max(nottake,maxres);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,k);
    }
};