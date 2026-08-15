class Solution {
public:
int dp[201][201];
bool vis[201][201];
    int solve(int i,int k,vector<vector<int>>&triangle){
        if(i==triangle.size()-1){//i is row and k is column.
            return triangle[i][k];
        }
        if(vis[i][k]){
            return dp[i][k];
        }
        //now we have options to go to k or k+1 on next row;
        int option1=solve(i+1,k,triangle);
        int option2=INT_MAX;
        if(k+1<triangle[i+1].size()){
        option2=solve(i+1,k+1,triangle);
        }
        vis[i][k]=true;
        return  dp[i][k]=triangle[i][k]+min(option1,option2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,triangle);
    }
};