class Solution {
public:
int mod=1e9+7;
int dp[102][102][102];
    int solve(int i,int g,vector<int>&profit,vector<int>&group,int Minprofit,int pft){
        if(i>=profit.size()){
            if(pft>=Minprofit){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][g][pft]!=-1){
            return dp[i][g][pft];
        }
        //now we have option to either commit this crime or not.
        //before committing crime check if we have enough people to commit this crime.
        int commit=0;
        if(g>=group[i]){
         commit=solve(i+1,g-group[i],profit,group,Minprofit,min(Minprofit,pft+profit[i]));
        }

        int dontcommit=solve(i+1,g,profit,group,Minprofit,pft);
        return  dp[i][g][pft]=(commit+dontcommit)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,profit,group,minProfit,0);
    }
};