class Solution {
public:
int dp[1002][1002];
int solve(int i,int target,vector<int>&nums){
    if(i==nums.size()){
        if(target==0){
            return 0;
        }
        else{
            return -1e9;
        }
    }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int take=-1e9;
        int skip=-1e9;
        if(target>=nums[i]){
        take=1+solve(i+1,target-nums[i],nums);
        }
        skip=solve(i+1,target,nums);
        return dp[i][target]=max(take,skip);
    
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return (solve(0,target,nums)<-1)? -1 : solve(0,target,nums);
    }
};