class Solution {
public:
int dp[366];
    int solve(int i,vector<int>&days,vector<int>&costs){
        if(i>=days.size()){
            return 0;///hogya bhai tum out of bounds aa chuke ho,
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //now each day we havce 3 options.
        int option1=costs[0]+solve(i+1,days,costs);
        int j=i; 
        while(j<days.size() && days[j]<days[i]+7){
            j++;
        }
        int option2=costs[1]+solve(j,days,costs);
        int k=i;
        while(k<days.size() && days[k]<days[i]+30){
            k++;
        }
        int option3=costs[2]+solve(k,days,costs);
        return dp[i]=min({option1,option2,option3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,costs);
    }
};