class Solution {
public:
int dp[1002][1002];
    int solve(int i,int j ,string&s,string&t){
        if(j==t.length()){
            return 1;//one way found
        }
        if(i==s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        if(s[i]==t[j]){
            take=solve(i+1,j+1,s,t);
        }
        int skip=solve(i+1,j,s,t);
        return dp[i][j]=skip+take;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
        
    }
};