class Solution {
public:
int LCS(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0 ){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
    int minInsertions(string s) {
        //bhai ye problem bohhooot easy hai . dekho abhi ke string mai se ek part pehle se palindromic subsequence hoga, tumhe bas jo non palidnromic subs hai (yani kitne elements hai ),, unka len find krna hai kyuki utne hee insertions tum kroge unke opp wale dir mai .. basically len of s - longest palindromic subsequence of s.
        string x=s;
        reverse(x.begin(),x.end());
        int LPS=LCS(s,x);
        return s.length()-LPS;
    }
};