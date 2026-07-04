class Solution {
public:
typedef long long x;

    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
       vector<vector<x>>dp(n+1,vector<x>(2,0));
       for(int i=1;i<=n;i++){
       ///odd wale mai take or skip ka max lo
       dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i-1][1]); 
       //even wale mai take or skip ka max lo
       dp[i][0]=max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
       }
       return max(dp[n][0],dp[n][1]);
    }
};