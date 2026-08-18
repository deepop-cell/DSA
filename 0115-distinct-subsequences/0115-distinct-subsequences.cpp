class Solution {
public:
int dp[1001][1001];
    int solve(int i, int j,string&s,string&t){
        // i for s and j for t
        if(j==t.length()){
            //we have formed one.
            return 1;
        }
        if(i>=s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //now we are at current index i and we have option to include it or not include it.
        int take=0;
        if(s[i]==t[j]){
           take=solve(i+1,j+1,s,t);
        }
        int skip=solve(i+1,j,s,t);
        return dp[i][j]=take+skip;
        
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
        
    }
};