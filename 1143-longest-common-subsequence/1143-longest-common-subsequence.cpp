class Solution {
public:
int dp[1001][1001];
int solve(string &s1,string &s2,int i,int j){
    if(i>=s1.length() || j>=s2.length()){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //ab manlo dono ke index par same element hai.
    if(s1[i]==s2[j]){
        return dp[i][j]=1+solve(s1,s2,i+1,j+1);//dono mai aage badh jao..
    }
    else{
        //s1!=s2 at i,j then ek ko aage badhao dusre ko nahi and max nikalo
        int include_i=solve(s1,s2,i,j+1);
        int include_j=solve(s1,s2,i+1,j);
        return dp[i][j]=max(include_i,include_j);
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(text1,text2,0,0);
    }
};