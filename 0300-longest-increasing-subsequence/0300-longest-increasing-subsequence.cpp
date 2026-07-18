class Solution {
public:
int dp[2501][2501];
int solve(int idx,int previdx,vector<int>&nums){
    if(idx==nums.size()){
        return 0;
    }
    if(dp[idx][previdx+1]!=-1){
        return dp[idx][previdx+1];
    }
    //for take 
    int take=0;
    if(previdx==-1 || nums[previdx]<nums[idx]){
        take=1+solve(idx+1,idx,nums);
    }
    //skip 
    int skip=solve(idx+1,previdx,nums);
    return dp[idx][previdx+1]=max(take,skip);
}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);

        
    }
};