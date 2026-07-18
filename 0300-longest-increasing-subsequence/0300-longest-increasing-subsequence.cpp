class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //state defintion.. dp[i][j]=lis uptill jth index..
        int n=nums.size();
        vector<int>dp(n,1);
        int maxlis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxlis=max(maxlis,dp[i]);
                }
            }
        }
        return maxlis;
    }
};