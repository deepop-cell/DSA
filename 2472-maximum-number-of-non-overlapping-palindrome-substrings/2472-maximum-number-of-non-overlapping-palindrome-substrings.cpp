class Solution {
public:
int n;
bool ispalindrome(string &s,int i,int j){
    int k=i;
    int z=j;
    while(k<=z){
        if(s[k]!=s[z]){
            return false;
        }
        k++;
        z--;
    }
    return true;
}
    int solve(int i,int j,string &s,int k,vector<vector<int>>&dp){
        if(i>=n || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(ispalindrome(s,i,j)){
            int take=1+solve(j+1,k+j,s,k,dp);
            int grow=solve(i,j+1,s,k,dp);
            int slide=solve(i+1,j+1,s,k,dp);
            return  dp[i][j]=max({take,grow,slide});
        }
        else{
            int grow=solve(i,j+1,s,k,dp);
            int slide=solve(i+1,j+1,s,k,dp);
            return  dp[i][j]=max({slide,grow});
        }
        return 0;
    }
    int maxPalindromes(string s, int k) {
        n=s.length();
        if(k==1){
            return n;//max itne hee palindromes ban skenge tab
        }
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        int ans=solve(0,k-1,s,k,t);
        return ans;
    }
};