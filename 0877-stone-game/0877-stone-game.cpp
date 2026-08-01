class Solution {
public:
int dp[502][502];
    int solve(int i , int j, vector<int>&nums){
        if(i==j){
            //ek hee bacha hai to wahi uthana padega.
            return nums[i];
        }
        if(i>j){
            return 0;//cross kr gye ek dusre ko yni array empty hai ab/
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        //now p1 takes max from take_i and take_j. 
        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int p1=solve(0,n-1,nums);
        int totalscore=0;
        for(int &x:nums){
            totalscore+=x;
        }
        int p2=totalscore-p1;
        return (p1>p2);
        
    }
};