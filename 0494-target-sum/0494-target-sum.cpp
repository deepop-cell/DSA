class Solution {
public:
int dp[21][1001];
    int solve(int i,int sum,vector<int>&nums){
        if(i==nums.size()){
            //we have reached the end.
            //check if sum==0.
            if(sum==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        //bhai take krne ke lie ek codnition bhi to hai wo check kro.
        int take=0;
        if(nums[i]<=sum){
         take=solve(i+1,sum-nums[i],nums);
        }
        int skip=solve(i+1,sum,nums);
        return dp[i][sum]=take+skip;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //we need to check if there is a subset whose sum is totalsum+targetsum/2;
        int totalsum=0;
        for(int x:nums){
            totalsum+=x;
        }
        if(abs(target)>totalsum){
            return 0;
        }
        if((totalsum+target)%2!=0){
            return 0;
        }
        int find=(totalsum+target)/2;
        memset(dp,-1,sizeof(dp));
        return solve(0,find,nums);
    }
};