class Solution {
public:
int dp[301][5001];
    int solve(int i,int amount,vector<int>& coins){
        if(amount==0){
            //we got till the target so one way is found.
            return 1;
        }
        if(i==coins.size() && amount!=0){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        //now we can take or skip current coin.
        int take=0;
        if(coins[i]<=amount){
            take=solve(i,amount-coins[i],coins);//lelo aur aage badho.
        }
        int skip=solve(i+1,amount,coins);
        return  dp[i][amount]=skip+take;//discover all possible ways to reach till the target amount..

    }
    int change(int amount, vector<int>& coins) {
        //here we neeed no of such comibinations which can make the possible amount.
        if(amount==0){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,amount,coins);
        return ans;
    }
};