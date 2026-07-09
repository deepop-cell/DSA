class Solution {
public:
int dp[501][501];
    int solve(string s1,string s2,int i,int j){
        //base case.
        if(i==s1.length()){
            //insert krna padega 
            return s2.length()-j;//itne elements add krne padenge
        }
        else if(j==s2.length()){
            //delete krna padega
            return s1.length()-i;//itne elements delete krne padenge/
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else if(s1[i]==s2[j]){
            //equal hai no operations needed mobve ahead in both.
            return dp[i][j]=solve(s1,s2,i+1,j+1);
        }
        else{
            //unequal hai to 3 chiz kr skye, jissse min aaye usko le liyooo.
            int insert=1+solve(s1,s2,i,j+1);
            int del=1+solve(s1,s2,i+1,j);
            int replace = 1+ solve(s1,s2,i+1,j+1);
            return dp[i][j]=min({insert,del,replace});
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);
    }
};