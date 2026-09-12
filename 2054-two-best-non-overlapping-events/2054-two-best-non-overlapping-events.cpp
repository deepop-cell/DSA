class Solution {
public:
int dp[100001][5];
    int solve(int i,int took,vector<vector<int>>&events,vector<int>&start){
        if(i>=events.size()|| took==2){
            return 0;
        }
        if(dp[i][took]!=-1){
            return dp[i][took];
        }
        //we have option to take or skip current interval.
        int next_idx=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
        int take=events[i][2]+solve(next_idx,took+1,events,start);
        int skip=solve(i+1,took,events,start);
        return  dp[i][took]=max(take,skip);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
       sort(events.begin(),events.end());
       vector<int>start(n);
       for(int i=0;i<n;i++){
        start[i]=events[i][0];
       }
       memset(dp,-1,sizeof(dp));
       return solve(0,0,events,start);
    }
};