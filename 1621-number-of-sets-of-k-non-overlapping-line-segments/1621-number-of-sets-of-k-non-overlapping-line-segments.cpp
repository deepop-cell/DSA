class Solution {
public:
int N;
int dp[1005][1005][5];
int mod=1e9+7;
int solve(int i,int k,int covered){
    if(k==0){
        if(covered==0){
            return 1;
        }
        return 0;
    }
    if(i==N){
        return 0;
    }
    if(dp[i][k][covered]!=-1){
        return dp[i][k][covered];
    }
    int start=0;
    int dontstart=0;
    if(covered==0){
    //we have two options , start a segment from current or skip/
    start=solve(i+1,k,1);
    dontstart=solve(i+1,k,0);
    return dp[i][k][covered]=(start+dontstart)%mod;
    }
    int extend=0;
    int end=0;
     if(covered==1 || covered==2){
        //we can either extend this segment now or end this segment here/
     extend=solve(i+1,k,min(2,covered+1));
     end=solve(i,k-1,0);//in end we dont do i+1 because shared endpoints is allowed in the qsn.
    }
    return dp[i][k][covered]=(extend+end)%mod;
}
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        N=n;
       return solve(0,k,0);
    }
};