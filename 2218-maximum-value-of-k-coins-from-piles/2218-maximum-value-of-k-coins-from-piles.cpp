class Solution {
public:
int dp[1009][2009];
    int solve(int i,int k,vector<vector<int>>&piles){
        if(i==piles.size()){
            return 0;
        }
        if(k==0){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        //now we have option, ya to current pile ko skip karo , ya to usse ek ya do ya k uth alo/
        int skip=solve(i+1,k,piles);
        //now for take, what we can do is take 1 ,2 ,3 .. min(piles[i].size,k) piles.
        int sum=0;
        int maxres=-1;
        int x=min((int)piles[i].size(),k);
        for(int j=0;j<x;j++){
            sum+=piles[i][j];
            maxres=max(maxres,sum+solve(i+1,k-(j+1),piles));
        }
        return dp[i][k]=max(skip,maxres);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k,piles);
    }
};