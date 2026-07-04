class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        //dp[i]=lis ending at ith index
        int maxlis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                //for making increasing subsequence.
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    maxlis=max(maxlis,dp[i]);///keep updating the max lis lenght.
                }
            }
        }
        return maxlis;
     
        
    }
};