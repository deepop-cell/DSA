class Solution {
public:
int dp[31][3001];
    int solve(int i,int sum,vector<int>&s){
        if(i==s.size()){
            // u have reached the nd
            return 0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int skip=solve(i+1,sum,s);
        //for take check
        int take=0;
        if(s[i]<=sum){
        take=s[i]+solve(i+1,sum-s[i],s);
        }
        return dp[i][sum]=max(take,skip);
    }
    int lastStoneWeightII(vector<int>& s) {
        //see each time we have x and y from the nums and we diff them. we want summation of diff to be min . this means we are kind of paritioning the array into two subsets  and we want their diff of sums to be minimum this is only possible when sum of subset is as much close to totalarrsum/2. and we will finally return ..
        int totalsum=0;
        for(int x:s){
            totalsum+=x;
        }
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int max_achievablesum=solve(0,totalsum/2,s);
        return (totalsum-max_achievablesum)-max_achievablesum;
        //now chase totalsum/2;   
    }
};