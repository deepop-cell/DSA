class Solution {
    //ASKED BY MICROSOFT>>>>>>
public:
int dp[501][501];
bool vis[501][501];
    int solve(int i,int t,vector<int>&s){
        if(i>=s.size()){
            return 0;//so small that max ignores it.
        }
        if(vis[i][t]){
            return dp[i][t];
        }
        //now at current inde we have option to include it or not.
        int take=(t*s[i])+solve(i+1,t+1,s);
        int skip=solve(i+1,t,s);
        vis[i][t]=true;
        return dp[i][t]=max(skip,take);
    }
    int maxSatisfaction(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        sort(s.begin(),s.end());
        return solve(0,1,s);
    }
};