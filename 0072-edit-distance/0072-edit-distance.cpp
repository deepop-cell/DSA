class Solution {
public:
    int minDistance(string word1, string word2) {
        //bottom up approach......
        //state defn dp[i][j] ka matlab hai no of operations to make word1 of i len to word2 of j len....
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){//ek ka b len 0 hai to bache hue ke jitne len ka delettion/insertion karna padega.
                    dp[i][j]=i+j;
                }
                else if(word1[i-1]==word2[j-1]){
                    //agar barabar hai to no operations needed chup chap dono mai aage badh jao,...
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    //unequal hai to min of insert,del aur replace daldena . 1+ krke kyuki ek operation to kr rhee rhw ho..
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
        
    }
};