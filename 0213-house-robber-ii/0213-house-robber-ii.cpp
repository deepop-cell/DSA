class Solution {
public:
int dp[101];
    int solve(vector<int>&nums,int i,int end){
        if(i<0 || i>end){
            return 0;//out of bounds hai
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int steal=nums[i]+solve(nums,i+2,end);
        int skip=solve(nums,i+1,end);
        return dp[i]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        memset(dp,-1,sizeof(dp));
        int ans1=solve(nums,0,n-2);//last ko ignore kro
         memset(dp,-1,sizeof(dp));//reset memset before second run
        int ans2=solve(nums,1,n-1);//first ko ignore kro
        return max(ans1,ans2);
        
    }
};