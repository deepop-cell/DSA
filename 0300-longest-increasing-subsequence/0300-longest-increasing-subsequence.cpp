class Solution {
public:
int dp[2501][2501];
int solve(int idx,int prev,vector<int>&nums){
    if(idx>=nums.size()){
        return 0;//out of bounds hai.
    }
    if(dp[idx][prev+1]!=-1){//intially prev -1 hai to array mai -1 index thodi hoga to isliye prev+1.
        return dp[idx][prev+1];
    }
    int take=0;
    if(prev==-1 || nums[prev]<nums[idx]){
        //take krna hai .(p wala index ka chota hona chaiye for increasing subsequence).
         take=1+solve(idx+1,idx,nums);//ab add krlia hai to prev ke badle idx jayga
    }
    //skip krna hai(no special condition required)
    int skip=solve(idx+1,prev,nums);
    return dp[idx][prev+1]=max(take,skip);//wo -1 hai initially to isliye prev+1
}

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return solve(0,-1,nums);
        
    }
};