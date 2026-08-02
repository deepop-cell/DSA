class Solution {
public:
bool dp[100001];
bool vis[100001];
    bool solve(int n){
        if(n==0){
            // no stones left for alice therefore she lost.
            return false;
        }
        if(n==1){
            return true;
        }
        if(vis[n]){
            return dp[n];
        }
        for(int k=1;k*k<=n;k++){
            if(!solve(n-k*k)){
                vis[n]=true;
               return dp[n]= true;//maine k*k elements utha lie ab p2 ki baari aur agar uska false aa gya to mai jit jaunga
            }
        }
        vis[n]=true;
        return dp[n]=false;//wo for loop mai kabhi hara hee nhi matlab mai har gaya 
    }
    bool winnerSquareGame(int n) {
    memset(dp,false,sizeof(dp));
    memset(vis,false,sizeof(vis));
    return solve(n);        
    }
};