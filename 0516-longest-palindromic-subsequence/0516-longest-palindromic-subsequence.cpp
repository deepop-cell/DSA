class Solution {
public:
int dp[1005][1005];
    int solve(int i,int j,string&s1,string&s2,int n,int m){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //now if current char mathes then move ahead in both
        if(s1[i]==s2[j]){
          return dp[i][j]= 1+solve(i+1,j+1,s1,s2,n,m);
        }
        else{
          return dp[i][j]= max(solve(i+1,j,s1,s2,n,m),solve(i,j+1,s1,s2,n,m));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        //its just lcs of s and revs
        string revs=s;
        reverse(revs.begin(),revs.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,revs,n,n);
    }
};