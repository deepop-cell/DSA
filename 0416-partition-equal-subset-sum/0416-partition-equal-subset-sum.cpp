class Solution {
public:
//just find if there exists a subset of this whose sum =total arr wt/2.
int dp[201][10001];
int solve(int i,vector<int>&nums,int sum){
    if(sum==0){
        return true;
    }
    if(sum!=0 && i==nums.size()){
        return false;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    bool take=false;
    bool skip=false;
    if(nums[i]<=sum){
        //then u can take.
        take=solve(i+1,nums,sum-nums[i]);
    }
    skip=solve(i+1,nums,sum);
    return dp[i][sum]=  ( skip || take);//auto casts bool into 0/1.
}
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int totalwt=0;
        for(int x:nums){
            totalwt+=x;
        }
        if(totalwt%2!=0){
            //total wt odd hai to equal sum mai split hee nahi kr skte ho,
            return false;
        }
        int targetsum=totalwt/2;
        return solve(0,nums,targetsum);
    }
};