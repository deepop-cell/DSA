class Solution {
public:
int dp[601][101][101];
    int solve(int idx, int m , int n, vector<string>&strs){
        if(m==0 && n==0){
            return 0;
        }
        if(idx>=strs.size()){
            return 0;
        }
        //now to check if we can take or not.
        if(dp[idx][m][n]!=-1){
            return dp[idx][m][n];
        }
        int zero=0;
        int one=0;
        for(char& ch:strs[idx]){
            if(ch=='1'){
                one++;
            }
            else{
                zero++;
            }
        }
        //***************TAKE*******************
        //now check if we can take current index or not..
        int take=0;
        if(zero<=m && one<=n){
            take=1+solve(idx+1,m-zero,n-one,strs);
        }
        //*************SKIP***************
        int skip=solve(idx+1,m,n,strs);
        return dp[idx][m][n]=max(skip,take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,strs);
    }
};