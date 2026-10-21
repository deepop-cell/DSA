class Solution {
public:
long long dp[10001];
     long long solve(int i,vector<int>&nums){
        if(i==nums.size()-1){
            //end aa gya hai 
            return 0;
        }
        if(i>=nums.size()){
            return INT_MAX;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //we have otpions 
        long long steps=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            long long x=solve(i+j,nums);
            steps=min(steps,x);
        }
        return dp[i]= 1+steps;
     }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};