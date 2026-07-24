class Solution {
public:
int dp[101][10001]; //we need i*i<=n so i=100.
    int solve(int i,int sum){
        if(sum==0){
            return 0;//found the manjil//
        }
        if(i*i>sum && sum!=0){
            return 1e9;//so min ignores it.
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int take=1e9;//agar take ka condition false hua to wo 0 ka 0 reh jayga so min se  0 return ho jayga so to avoid that we give take a very  big initial value 
        if(i*i<=sum){
            take=1+solve(i,sum-(i*i));//we took a number so we did +1.
        }
        int skip=solve(i+1,sum);
        return dp[i][sum]=min(skip,take);
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(1,n);
        return ans;
    }
};