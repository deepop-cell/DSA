class Solution {
public:
int dp[21][1001];
int solve(int i,vector<int>&nums,int sum){
    if(i==nums.size()){
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
    int take=0;
    int skip=0;
    //check if we can take.
    if(nums[i]<=sum){
        take=solve(i+1,nums,sum-nums[i]);
    }
    skip=solve(i+1,nums,sum);
    return dp[i][sum]=take+skip;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        for(auto &x:nums){
            totalsum+=x;
        }
        memset(dp,-1,sizeof(dp));
        if(abs(target)>totalsum){
            return false;
        }
        if((target+totalsum)%2!=0){
            return 0;
        }
            int x=(target+totalsum)/2.0;
            return solve(0,nums,x);
        
    }
};