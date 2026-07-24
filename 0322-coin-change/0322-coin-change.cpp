class Solution {
public:
int dp[13][10001];
    int solve(int i,int amount,vector<int>&coins){
        if(amount==0){
            //means manjil aa gai hai..
            return 0;
        }
        if(i==coins.size() && amount!=0){
            return 1e9;//return so big value that min ignores it.
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        //ab har ek coin par take aur skip ke cases banao.. now here since we  have options to take a coin multiple times we wont do i+1 in case of take..
        int take=1e9;//see we intialise with this because of coins[i]>amount so if we start take=0 it will remain 0 and min(take,skip) will do return 0. so to avoid this we start with a very large value..
        if(coins[i]<=amount){
            take=1+solve(i,amount-coins[i],coins);//hum ye coin wapas le skte hai jab tk coins[i]<=amount hai so keep i here only,..
            //and since we are taking one coin so do take=1+recursion.. adding 1 means we took one coin..
        }
        int skip=solve(i+1,amount,coins);
        return dp[i][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        int ans= solve(0,amount,coins);
        return (ans>=1e9)?-1:ans;//if no possible way then means we found no way and every time we return 1e9,, so do it -1.
    }
};