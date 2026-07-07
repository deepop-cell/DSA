class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //bottom up 
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        //state definition dp[i][j]=lcs of s1 of lentgh i and s2 of lentgh j .(note length hai index nahi ....)
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                //agar i ya j mai se ek b 0 hai to 0..
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                
                //manlo equal ho gye to .
                else if(text1[i-1]==text2[j-1]){
                    //dono mai aage badh jao.( bottom up mai peeche jaate hai)
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    //unequal hai to ek ko move kro dusre ko nhi and max  nikalo
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];// this returns lcs of s1 of lentgh m and s2 of lentgh n
        
    }
};