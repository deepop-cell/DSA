class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //state definiton dp[i][j]= longest commmon susbeuqnece len of s1 of len i and s2 of len j
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        //now fill this dp 2d array and return dp[n][m];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                else{
                    if(text1[i-1]==text2[j-1]){
                        //equal hai to increment len by 1 because common hai and move in both 
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        //unequal hai to move towards the side jo maximum length de sake asani  se,,
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[n][m];
    }
};