class Solution {
public:
int dp[10001];
    int solve(int i,vector<int>&nums){
        if(i==nums.size()-1){
            //we have reached .
            return 0;
        }
        if(i>=nums.size()){
            return 1e9;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //now we have options to take any jumps from 1 to nums[i;]
        long long min_ways=INT_MAX;
        for(int j=1;j<=nums[i];j++){
           min_ways=min(min_ways,(long long)1+solve(i+j,nums));
        }
        return dp[i]=min_ways;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};