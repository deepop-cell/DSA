class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;//this will count no of trues///
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i<=n-L;i++){
                int j=L+i-1;//L len ka substring ke lie j ye hona chaiye,...
                if(L==1){
                    //1 len ke substring to palidnromic hee hote hai yar..
                    dp[i][j]=true;
                }
                else if(L==2){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                else{
                    //L>2.....
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]){
                    //agar true hua to cnt++;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};