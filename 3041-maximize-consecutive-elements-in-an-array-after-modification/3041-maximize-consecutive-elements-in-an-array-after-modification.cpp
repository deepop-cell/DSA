class Solution {
public:
int dp[100001][2];
    int solve(int i , int inc , vector<int>&nums){
        if(dp[i][inc]!=-1){
            return dp[i][inc];
        }
        //we have two choices ya to iska +1 dhundo ya to exact equal ahead +1 dhundho 
        int best=1;
        int currval=nums[i]+inc;
        int j1=lower_bound(nums.begin()+i+1,nums.end(),currval)-nums.begin();
        if(j1<nums.size() && nums[j1]==currval){
            best=max(best,1 + solve(j1,1,nums));//we found exact this and did inc +1 at it . 
        }
        int j2=upper_bound(nums.begin()+i+1,nums.end(),currval)-nums.begin();
        if(j2<nums.size() && nums[j2]==currval+1){
            best=max(best,1+solve(j2,0,nums));//i already landed on +1 so keep inc as 0. 
        }
        return dp[i][inc]=best;
    }
    int maxSelectedElements(vector<int>& nums) {
        int ans=1;
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            //we have choice of either inc this and start or keep it as it is and start 
            ans=max({ans,solve(i,0,nums),solve(i,1,nums)});
        }
        return ans;
    }
};