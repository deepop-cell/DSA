class Solution {
public:
int dp[1001][1001];
int solve(int idx, int prev,vector<vector<int>>&pairs){
    if(idx>=pairs.size()){
        return 0;
    }
    if(dp[idx][prev+1]!=-1){
        return dp[idx][prev+1];
    }
    //now condition for taking.
    int take=0;
    if(prev==-1 || pairs[prev][1]<pairs[idx][0]){
        take=1+solve(idx+1,idx,pairs);
    }
    //now skip
    int skip=solve(idx+1,prev,pairs);
    return dp[idx][prev+1]=max(skip,take);
    
}
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        //sort the array first.
        sort(pairs.begin(),pairs.end());
         return solve(0,-1,pairs);
        
    }
};