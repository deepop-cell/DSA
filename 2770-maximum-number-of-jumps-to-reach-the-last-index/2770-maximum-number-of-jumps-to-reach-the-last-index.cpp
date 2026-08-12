class Solution {
public:
int dp[1001];
bool vis[1001];
    int solve(int i,vector<int>&nums,int target){
        if(i==nums.size()-1){
            return 0;//manzil aa gai hai guyz
        }
        if(i>=nums.size()){
            //matlab tum baahar aa gye ho .return so small that max ignores it/
            return INT_MIN;
        }
        if(vis[i]){
            return dp[i];
        }
        int jumps=-1;//if no path found it will be -1 only
        for(int j=i+1;j<nums.size();j++){

            if(abs(nums[j]-nums[i])<=target){
            int subproblem=solve(j,nums,target);
            if(subproblem!=-1){
            jumps=max(jumps,1+subproblem);//conditon for jumping.
            }
            }
        }
        vis[i]=true;
        return dp[i]=jumps;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int x=solve(0,nums,target);
        if(x==0){
            return -1;
        }
        else{
            return x;
        }
    }
};