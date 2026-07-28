class Solution {
public:
bool dp[10001];
bool vis[10001];
    bool solve(int idx,vector<int>&nums){
        if(idx==nums.size()-1){
            return true;
        }
        if(idx>=nums.size()){
            return false;
        }
        bool res=false;
        if(vis[idx]){
            return dp[idx];
        }
        for(int k=1;k<=nums[idx];k++){
            //we can make atmost index values jumps. so try all.
            bool x=solve(idx+k,nums);
            if(x==true){
                vis[idx]=true;
                return dp[idx]=true;
            }
        }
        vis[idx]=true;
        return dp [idx]=res;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,false,sizeof(dp));
        memset(vis,false,sizeof(vis));
        return solve(0,nums);
    }
};