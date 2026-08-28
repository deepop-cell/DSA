class Solution {
public:
bool taken[17];
    bool solve(int i,int k,int currsum,vector<int>&nums,int t){
        if(k==1){
            return true;
        }
        if(currsum==t){
            return solve(0,k-1,0,nums,t);
        }
        if(i>=nums.size()){
            return false;
        }
        bool take=false;
        if( !taken[i] && currsum+nums[i]<=t){
            taken[i]=true;
            take=solve(i+1,k,currsum+nums[i],nums,t);
            taken[i]=false;

        }
        bool skip=solve(i+1,k,currsum,nums,t);
        return (take || skip);
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int &x:nums){
            total+=x;
        }
        if(total%k!=0){
            return false;
        }
        int target=total/k;
        return solve(0,k,0,nums,target);
    }
};