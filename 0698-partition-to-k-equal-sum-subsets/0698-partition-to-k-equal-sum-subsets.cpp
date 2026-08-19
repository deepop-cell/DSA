class Solution {
public:
bool vis[20];
    int solve(int i,int target,int currsum,int k,vector<int>&nums){
        if(k==1){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if(currsum==target){
            return solve(0,target,0,k-1,nums);
        }
        bool take=false;
        if( !vis[i]&& currsum+nums[i]<=target){
            vis[i]=true;
            take=solve(i+1,target,currsum+nums[i],k,nums);
            vis[i]=false;//backtracking.
        }
        bool skip=solve(i+1,target,currsum,k,nums);
        return (take || skip);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(vis,false,sizeof(vis));
        int total=0;
        for(int &x:nums){
            total+=x;
        }
        if(total%k!=0){
            return false;
        }
        int chase=total/k;
        return solve(0,chase,0,k,nums);
    }
};