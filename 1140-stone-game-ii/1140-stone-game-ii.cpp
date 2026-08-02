class Solution {
public:
int dp[2][101][1001];
    int solveforalice(int person,int i , vector<int>&piles,int M){
        if(i>=piles.size()){
            return 0;
        }
        if(dp[person][i][M]!=-1){
            return dp[person][i][M];
        }
        int stones=0;
        int res=(person==1)?-1:INT_MAX;
        for(int x=1;x<=2*M;x++){
            if(person==1){
                if(i+x-1<piles.size())
            stones+=piles[i+x-1];
            res=max(res,stones+solveforalice(0,x+i,piles,max(M,x)));
            }
            else{
                //bob ka chance hai.
                res=min(res,solveforalice(1,x+i,piles,max(M,x)));
            }
        }
        return  dp[person][i][M]=res;

        }
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solveforalice(1,0,piles,1);
        
    }
};