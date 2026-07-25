class Solution {
public:
int dp[201][1001];
    int solve(int i,int sum , vector<int>&nums){
        if(sum==0){
            //manjil pahuch gye hai..
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        //***********TAKE**********
        int take=0;
        if(nums[i]<=sum){
             take=solve(0,sum-nums[i],nums);//again start from 0 to find all possibilities as observed from seeing the test cases,
        }
        int skip=solve(i+1,sum,nums);
        return dp[i][sum]=skip+take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        //after seeing the test cases we  can see that whenever we are taking a element we are starting again from 0th index..
        memset(dp,-1,sizeof(dp));
        return solve(0,target,nums);
    }
};