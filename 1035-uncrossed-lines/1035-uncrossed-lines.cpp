class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //note that for lines, we need that order must specefic and no must be same so jusr return the lentgh of longest common seuqeucne .. its that simple babe.
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }
                else if(nums1[i-1]==nums2[j-1]){
                    //same hai then inc len by 1 and move diagnpoally upwards/
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    //unequal . then find both ways and take the maximum of ti
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
};