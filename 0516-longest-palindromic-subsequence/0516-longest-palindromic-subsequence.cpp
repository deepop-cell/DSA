class Solution {
public:
    int longestPalindromeSubseq(string s) {
      //idea ye hai ki . lps is lcs of string and its reverse.
      string x=s;
      reverse(x.begin(),x.end());
      //state def : dp[i][j]=LCS len of s1 of len i and s2 of len j/...
      int n=s.length();
      vector<vector<int>>dp(n+1,vector<int>(n+1));
      for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            //agar ek b string empty hua to lcs 0 ho jayga.
            if(i==0 || j==0 ){
                dp[i][j]=0;
            }
            else if(s[i-1]==x[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                //unequl hai..
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
      }
      return dp[n][n];
    }
};