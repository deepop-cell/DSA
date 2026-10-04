class Solution {
public:
    bool solve(int i,long long sum,int k,vector<int>&nums,vector<bool>&vis,long long chase){
        if(k==1){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if(sum==0){
            return solve(0,chase,k-1,nums,vis,chase);
        }
        bool take=false;
        if(!vis[i] && sum-nums[i]>=0){
            vis[i]=true;
            take=solve(i+1,sum-nums[i],k,nums,vis,chase);
            vis[i]=false;
        }
        if(take){
            return true;
        }
        bool skip=solve(i+1,sum,k,nums,vis,chase);
        if(skip){
            return true;
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        vector<bool>vis(nums.size(),false);
        long long sum=0;
        for(int &x:nums){
            sum+=x;
        }
        if(sum%4!=0){
            return false;
        }
        return solve(0,sum/4,4,nums,vis,sum/4);
    }
};