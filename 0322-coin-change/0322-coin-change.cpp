class Solution {
public:
int dp[13][10001];
    int solve(int i,int sum,vector<int>&nums){
        if(i==nums.size()){
            if(sum==0){
                return 0;
            }
            else{
                return 1e9;
            }
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(i>nums.size()){
            return 1e9;
        }
        int take=1e9;
        if(sum>=nums[i]){
            take=1+solve(i,sum-nums[i],nums);
        }
        int skip=solve(i+1,sum,nums);
        return dp[i][sum]=min(skip,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,amount,coins);
        return (ans==1e9)?(-1):ans;
    }
};