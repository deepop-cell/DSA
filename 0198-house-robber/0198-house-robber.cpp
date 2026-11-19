class Solution {
public:
long long dp[101];
   long long solve(int i, vector<int>&nums){
    if(i>=nums.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    long long rob=nums[i]+solve(i+2,nums);
    long long skip=solve(i+1,nums);
    return dp[i]=max(skip,rob);
   }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        //see at each house we have options to either rob it or skip it / so we can write a dp thing 
        return solve(0,nums);
    }
};