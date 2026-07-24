class Solution {
public:
int dp[301][11];
    int solve(vector<int>&jd,int n , int idx, int d){
        if(d==1){
            int maxD=jd[idx];
            for(int i=idx+1;i<n;i++){
                maxD=max(maxD,jd[i]);
            }
            return maxD;
        }//if only 1 day is left,then do all left tasks in one day and return the max.
        if(dp[idx][d]!=-1){
            return dp[idx][d];
        }
        int res=jd[idx];
        int finalres=INT_MAX;
        int maxD=INT_MIN;
        /*
        so see. what we are doing. 
        take index={idx} wala job in first day and move ahead.(for loop ka first iteration..)
        take index ={idx,idx+1} wala job in first day and move ahead(for loop  ka second iteration)..
        and so on move and store it in res and return min of the res obtained in final res... return the finalrs..
        */
        //i represents edning job for the current day and idx means starting job for the current day.
        for(int i=idx;i<=n-d;i++){//go till n-d to ensurre ki atleast ek task bacha ho aage ke days ke liye.
            maxD=max(maxD,jd[i]);
            res=maxD+solve(jd,n,i+1,d-1);//taken first i tasks in todays job, now for ahead days call from next index
            finalres=min(finalres,res);
        }
        return  dp[idx][d]=finalres;

    }
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(n<d){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(jd,n,0,d);
    }
};