class Solution {
public:
bool dp[10001];
bool vis[10001];
bool solve(int i , vector<int>&nums){
    if(i==nums.size()-1){
        return true;
    }
    if(vis[i]){
        return dp[i];
    }
    //now we have options for jumping , 1 to nums[i].
    for(int j=1;j<=nums[i];j++){
        if(solve(i+j,nums)){
            vis[i]=true;
            return dp[i]=true;
        }
    }
    vis[i]=true;
    return dp[i]=false;
}
    bool canJump(vector<int>& nums) {
        memset(dp,false,sizeof(vis));
        memset(vis,false,sizeof(vis));
        return solve(0,nums);
    }
};