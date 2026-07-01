class Solution {
public:
typedef long long x;
int n;
x dp[100001][2];//2 chizen change ho rhi , ek index aur dusra flag(T/F).
    x solve(int idx,vector<int>&nums,bool flag){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        x skip=solve(idx+1,nums,flag);
        x val=nums[idx];
        if(!flag){
            val=(-1)*val;
        }
        x take=val+solve(idx+1,nums,!flag);
        return dp[idx][flag]=max(skip,take);//memoisation
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,true);//starting index is even so flag=true;
        
    }
};