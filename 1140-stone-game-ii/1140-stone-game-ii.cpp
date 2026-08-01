class Solution {
public:
int dp[2][101][1001];
    int solveforalice(int person,int i,int M,vector<int>&piles){
        if(i>=piles.size()){
            return 0;
        }
        //now we have chocies to take from first 1 to ... 2*M stones, so we will discover all possibilities.
        if(dp[person][i][M]!=-1){
            return dp[person][i][M];
        }
        int stones=0;//this counts number of stones picked nby alice.
        int result=(person==1)?-1:INT_MAX;
        for(int x=1;x<=2*M;x++){
            if(person==1){
                //alice ki baari hai.
                //when khud ki turn expect u to be best.
                if(i+x-1<piles.size()){
                stones+=piles[i+x-1];
                }
                result=max(result,stones+solveforalice(0,x+i,max(M,x),piles));
            }
            else{
                //bob ki baari hai. when oppononets turn expect it to be worst.(min) for me
                //yaha stones+= nhi krenge kyuki stones to alice ka count rkh rha hai.
                result=min(result,solveforalice(1,x+i,max(M,x),piles));
            }
        }
        return dp[person][i][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int p1=solveforalice(1,0,1,piles);
        return p1;
        
    }
};