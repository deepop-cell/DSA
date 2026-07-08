class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int total_asci_sum=0;
        for(char ch:s1){
            total_asci_sum+=(int)ch;
        }
        for(char ch:s2){
            total_asci_sum+=(int)ch;
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 | j==0 ){
                    dp[i][j]=0;
                }
                else if( s1[i-1]==s2[j-1]){
                    //same hai . then add asci value.
                    dp[i][j]=(int)s1[i-1]+dp[i-1][j-1];
                }
                else{
                    //unequal hai to ek ek koo hata ke jo max aa rha ho wo leleo
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int max_asci_sum_cs=dp[n][m];
        return total_asci_sum - (2*max_asci_sum_cs);
        
    }
};