class Solution {
public:
    string longestPalindrome(string s) {
    int n=s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1));
    int maxl=0;
    int startingpoint=-1;
    //state defn: dp[i][j]=true matlab substr from i to j is a palindrome...
    for(int L=1;L<=n;L++){
        for(int i=0;i<n-L+1;i++){
            int j=L+i-1;
            if(L==1){
                dp[i][j]=true;
            }
            else if(L==2){
                if(s[i]==s[j]){
                    dp[i][j]=true;
                }
            }
            else{
                //L>2..
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                }
            }
            //ab dekho,..
            if(dp[i][j]){
                int len=j-i+1;
                if(len>maxl){
                    maxl=len;
                    startingpoint=i;
                }
            }
        }
    }
    return s.substr(startingpoint,maxl);
    }
};