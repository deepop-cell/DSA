class Solution {
public:
    bool canPartition(vector<int>& nums) {
        ///bottom up.
        //dp[i][j]= is it possible for first i elements to have a subset sum equals to j..
        int n=nums.size();
        int targetsum=0;
        for(auto &x:nums){
            targetsum+=x;
        }
        if(targetsum%2!=0){
            return false;
        }
        targetsum/=2;
        vector<vector<bool>>dp(n+1,vector<bool>(targetsum+1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;//sum 0 means found na!!!
        }
        for(int j=0;j<targetsum+1;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<targetsum+1;j++){
                bool take=false;
                bool skip=false;
                if(nums[i-1]<=j){
                    take=dp[i-1][j-nums[i-1]];
                }
                skip=dp[i-1][j];
                dp[i][j]=(skip|| take);
            }
        }
        return dp[n][targetsum];
    }
};