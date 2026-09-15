class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        //we will use our blueprint.
        //dp[i][j]= substring from i to j is a palindorme or not,
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int maxlen=0;
        string ans="";
        for(int L=1;L<=n;L++){
            //try eevry len
            for(int i=0;i<n+1-L;i++){
                //tryt eevery starting point.
                int j=L+i-1;
                if(L==1){
                    dp[i][j]=true;//1 len ka to hmesha pal hota h
                }
                else if(L==2){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    if(L>maxlen){
                        maxlen=L;
                        ans=s.substr(i,L);
                    }
                }
            }
        }
        //now we have filled the dp table.
        return ans;

    }
};