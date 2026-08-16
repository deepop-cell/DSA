class Solution {
public:
int dp[1005];
    int solve(int i,vector<int>&cost){
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //now we have options. like to move one or two steps
        int onestep=solve(i+1,cost);
        int twostep=solve(i+2,cost);
        return  dp[i]=cost[i]+min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int x=solve(0,cost);
        int y=solve(1,cost);
        return min(x,y);
    }
};