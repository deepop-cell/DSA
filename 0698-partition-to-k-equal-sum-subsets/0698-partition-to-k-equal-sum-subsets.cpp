class Solution {
public:
//we need to make a vis array to check if the gievn number was visisted previsuly.
bool vis[18];
    bool solve(int i,int currsum,int target,int k,vector<int>&nums){
        if(k==1){
            return true;//ek hee baki hai to yehi hoga
        }
        if(i>=nums.size()){
            return false;
        }
        if(currsum==target){
            return solve(0,0,target,k-1,nums);
        }
        //now u have choice to include current one or not
        bool take=false;
        bool skip=false;
        if( !vis[i] && nums[i]+currsum<=target){
            vis[i]=true;//i ko mai le rha hu
            take=solve(i+1,currsum+nums[i],target,k,nums);
            //ab undo krdo use
            vis[i]=false;
        }
        skip=solve(i+1,currsum,target,k,nums);
        return (skip || take);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(vis,false,sizeof(false));
        int total=0;
        for(int &x:nums){
            total+=x;
        }
        if(total%k!=0){
            return false;
        }
        int chase=total/k;
        return solve(0,0,chase,k,nums);
    }
};