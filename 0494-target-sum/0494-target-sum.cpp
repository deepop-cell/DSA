class Solution {
public:
int dp[21][1001];
bool vis[21][1001];
int solve(int i,int sum,vector<int>&nums){
    if(i==nums.size()){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(vis[i][sum]){
        return dp[i][sum];
    }
    //now we have option to take current in subsequence or not.
    int take=0;
    if(sum>=nums[i]){
        take=solve(i+1,sum-nums[i],nums);
    }
    int skip=solve(i+1,sum,nums);
    vis[i][sum]=true;
    return dp[i][sum]=take+skip;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        //total +target /2 chase krna hia subsequence sum..
        int total=0;
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        for(int &x:nums){
            total+=x;
        }
        if((total+target)%2!=0 || abs(target)>total){
            return 0;
        }
        int chase=(total+target)/2;
        return solve(0,chase,nums);
    }
};