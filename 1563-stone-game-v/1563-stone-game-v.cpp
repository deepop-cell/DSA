class Solution {
public:
int dp[501][501];
    int solve(vector<int>&stoneValue,vector<int>&prefix,int low,int high){
        if(low>=high){
            return 0;
        }
        if(dp[low][high]!=-1){
            return dp[low][high];
        }
        //now we have options to put parition.
        int res=INT_MIN;
        for(int i=low;i<high;i++){
            int stone=0;
            int lefthalf=0;
            int righthalf=0;
            lefthalf=(low==0)?prefix[i]:prefix[i]-prefix[low-1];
            righthalf=prefix[high]-prefix[i];
            if(lefthalf<righthalf){
                //we will discard righthalf and take lefthalf.
                stone+=lefthalf;
                res=max(res,stone+solve(stoneValue,prefix,low,i));
            }
            else if(lefthalf>righthalf){
                //we will discard lefthalf and take righthalf.
                stone+=righthalf;
                res=max(res,stone+solve(stoneValue,prefix,i+1,high));
            }
            else{
                //both are equal then we need to discover both possibilities and return max since alice has now choice to take both of them (i mean eitherof them , no restyriction);
                int x=lefthalf+solve(stoneValue,prefix,low,i);
                int y=righthalf+solve(stoneValue,prefix,i+1,high);
                 int mx=max(x,y);
                 res=max(res,mx);
            }
        }
        return  dp[low][high]=res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int n=stoneValue.size();
        vector<int>prefix(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stoneValue[i];
            prefix[i]=sum;
        }
        int maxscore=solve(stoneValue,prefix,0,n-1);
        return maxscore;
    }
};