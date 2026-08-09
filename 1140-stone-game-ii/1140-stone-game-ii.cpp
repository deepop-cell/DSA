class Solution {
public:
int dp[100][1000][2];
    int solveforalice(int i,int M ,vector<int>&piles,int person){
        if(i>=piles.size()){
            return 0;
        }
        if(dp[i][M][person]!=-1){
            return dp[i][M][person];
        }
        //now run a loop fromm 1 to 2*M.
        int res=(person==0)?INT_MIN:INT_MAX;
        int stones=0;
        for(int x=1;x<=2*M;x++){
            if(i+x-1<piles.size()){
            stones+=piles[i+x-1];
            }
            if(person==0){
                //alice ki chance hai so max kro result ko
                res=max(res,stones+solveforalice(i+x,max(M,x),piles,1));
            }
            else{
                //if bob ki chance then wo b optimally khelega so we get mini,um.
                res=min(res,solveforalice(i+x,max(M,x),piles,0));
            }
        }
        return dp[i][M][person]=res;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int score=solveforalice(0,1,piles,0);
        return score;
    }
};