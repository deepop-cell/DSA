class Solution {
public:
bool vis[16];

    bool solve(int i,int sum,int chase, int k,vector<int>&nums){
        if(k==1){
            return true;
        }
        if(i>=nums.size()){
            return false;
        }
        if(sum==chase){
            return solve(0,0,chase,k-1,nums);
        }
        //now we have option to either take current or not take it.
        bool take=false;
        if( !vis[i] && nums[i]+sum<=chase){
            vis[i]=true;//this index is taken while filling current bucket(subset).
            take=solve(i+1,sum+nums[i],chase,k,nums);
            vis[i]=false;///backtrackng.(jo kia h use undo b krna hai)

        }
        bool skip=solve(i+1,sum,chase,k,nums);
        return (skip || take);
        
    }
    bool makesquare(vector<int>& matchsticks) {
        //if we can split array in 4 equal parts ,i mean 4 susbest having equal sum , then we can make s square out of them.
        memset(vis,false,sizeof(vis));
        int total=0;
        for(int &x:matchsticks){
            total+=x;
        }
        int chase=total/4;
        if(total%4!=0){
            return false;
        }
        int y=4;
        return solve(0,0,chase,y,matchsticks);
    }
};