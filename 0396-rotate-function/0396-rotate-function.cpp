class Solution {
public:
long long dp[100001];
long long vis[100001];
    long long fn(int i,vector<int>&nums,long long &sum,long long &base){
        int n=nums.size();
        if(i==0){
            return base;
        }
        if(vis[i]){
            return dp[i];
        }
        vis[i]=true;
        return dp[i]=fn(i-1,nums,sum,base) + sum - n*(nums[n-i]);
    }
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        long long sum=0;
        long long base=0;
        for(int i=0;i<nums.size();i++){
            base+=1LL*(i)*(nums[i]);
        }
        for(int &x:nums){
            sum+=x;
        }
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        long long mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,fn(i,nums,sum,base));
        }
        return mx;
    }
};