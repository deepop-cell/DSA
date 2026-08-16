class Solution {
public:
long long mod=1e9+7;
long long  dp[1001];
    int solve(int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=(1LL*2*solve(n-1)+solve(n-3))%mod;
    }
    int numTilings(int n) {
        //bohot he acha question h , defn not a medium one,
        //dekho 2*N ko hum split kr skte hai, N-1 * 1, N-2*2 and so on krke, isme kuchh ways duplicate honge jo dominos se fill ho rhe honge, unhe avoud krne ke lie sirf trominos wale factor se multiply kreneg, so we get formula f(n)=2*(f(n-1))+f(n-3).
        memset(dp,-1,sizeof(dp));
        int ans=solve(n);
        return ans;
    }
};