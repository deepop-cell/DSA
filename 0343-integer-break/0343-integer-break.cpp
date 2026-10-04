class Solution {
public:
long long dp[101];
    int solve(int n){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        long long mx=1;
        for(int i=1;i<n;i++){
        mx=max({mx,(long long)i*(solve(n-i)),(long long)i*(n-i)});
        }
        return dp[n]=mx;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};