class Solution {
public:
int dp[502][502];
    int solve(int i,int j,vector<int>&piles){
        if(i==j){
            return piles[i];
        }
        if(i>j){
        return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //take i or take j,
        int take_i=piles[i]+min(solve(i+2,j,piles),solve(i+1,j-1,piles));
        int take_j=piles[j]+min(solve(i+1,j-1,piles),solve(i,j-2,piles));
        return  dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        int p1=solve(0,n-1,piles);
        int total=0;
        for(int &x:piles){
            total+=x;
        }
        int p2=total-p1;
        return p1>p2;
    }
};