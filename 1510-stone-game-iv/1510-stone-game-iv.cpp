class Solution {
public:
bool dp[100001];
bool vis[100001];
    bool solve(int n){
        if(n==0){
            return false;//mere lie ab bacha he nhi hai to mai har jaunga
        }
        if(n==1){
            return true;
        }
        if(vis[n]){
            return dp[n];
        }
        for(int k=1;k*k<=n;k++){
            if(!solve(n- k*k)){//samne wala har rha hai to tum jeet jaoge.
            vis[n]=true;
                return dp[n]=true;
            }
        }
        vis[n]=true;
        return dp[n]=false;
    }
    bool winnerSquareGame(int n) {
        memset(dp,false,sizeof(dp));
        return solve(n);
    }
};