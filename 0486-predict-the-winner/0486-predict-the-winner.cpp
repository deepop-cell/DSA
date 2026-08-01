class Solution {
public:
int dp[21][21];
    int solve(int i , int j , vector<int>&nums){
        if(i==j){
            return nums[i];//if only one lement left then wahi uthaoge na
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take_i=nums[i]+min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j]+min(solve(i+1,j-1,nums),solve(i,j-2,nums));
        return  dp[i][j]=max(take_i,take_j);//this is not greeedy way, but t=it dicovers all possbiliites and total sum from both paths and then return th best one.
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int p1= solve(0,n-1,nums);
        int totalscore=0;
        for(int &x:nums){
            totalscore+=x;
        }
        int p2=totalscore-p1;
        return (p1>=p2);
    }
};