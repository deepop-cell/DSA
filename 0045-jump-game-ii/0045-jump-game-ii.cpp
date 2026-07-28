class Solution {
public:
int dp[10001];
    int solve(int idx,vector<int>&nums){
        if(idx==nums.size()-1){
            return 0;//manjil aa gai ab aur kya hee jump kroge
        }
        if(idx>=nums.size()){
            return 1e9;//return so big that this case gets ignored by the min function
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int res=1e9;
        for(int k=1;k<=nums[idx];k++){
            res=min(res,solve(idx+k,nums));
        }
        return dp[idx]=1+res;//ek jump to kroge hee na out of the k loop options
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};