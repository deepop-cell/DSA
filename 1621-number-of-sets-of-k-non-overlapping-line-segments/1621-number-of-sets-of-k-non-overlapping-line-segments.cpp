class Solution {
public:
int dp[1002][1002][4];
int N;
int mod=1e9+7;
int solve(int i,int k,int covered){
    if(k==0){
        return covered==0;//means no open segments are left now
    }
    if(i==N){
        return 0;
    }
    if(dp[i][k][covered]!=-1){
        return dp[i][k][covered];
    }
    //now we have option, either to extend this segment or start a new segment.
    int skip=0;
    int start=0;
    if(covered==0){
        //we have 2 choices, ya to new segment start kro ya to isse bhi skip kardo.
        skip=solve(i+1,k,0);
        start=solve(i+1,k,1);
        return dp[i][k][covered]= (skip+start)%mod;
    }
    int extend=solve(i+1,k,min(covered+1,2));
    int end=0;
    if(covered==2 || covered==1){
    end=solve(i,k-1,0);//we can also start a new seg from here or not so keep i hereonly
    }
    return dp[i][k][covered]=(extend+end)%mod;
}
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        N=n;
        return solve(0,k,0);
    }
};