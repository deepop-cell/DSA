class Solution {
public:
typedef long long ll;

struct x{
    ll sum=-1;//for memoization check..
    vector<int>idx;
};
x dp[50001][4];
x solve(int i,int took,vector<vector<int>>&it,vector<int>&s){
    if(i>=it.size() || took ==4){
        return {0,{}};
    }
    if(dp[i][took].sum!=-1){
        return dp[i][took];
    }
    int next_idx=upper_bound(s.begin(),s.end(),it[i][1])-s.begin();
    x take=solve(next_idx,took+1,it,s);
    ll take_score=take.sum+it[i][2];
    x skip=solve(i+1,took,it,s);
    ll skip_score=skip.sum;
    if(take_score>skip_score){
        take.idx.push_back(it[i][3]);
        sort(take.idx.begin(),take.idx.end());
        return  dp[i][took]={take_score,take.idx};
    }
    else if(take_score==skip_score){
//take the lexicohraphically smallest/
    take.idx.push_back(it[i][3]);
    sort(take.idx.begin(),take.idx.end());
    if(take.idx<skip.idx){
        return dp[i][took]={take_score,take.idx};
    }
    else{
        return dp[i][took]={take_score,skip.idx};
    }
    }
    else{
        return dp[i][took]={skip_score,skip.idx};
    }
}
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>intervals_modified(n);
        for(int i=0;i<n;i++){
            intervals_modified[i]={intervals[i][0],intervals[i][1],intervals[i][2],i};
        }
        sort(intervals_modified.begin(),intervals_modified.end());
        vector<int>starting;
        for(int i=0;i<n;i++){
            starting.push_back(intervals_modified[i][0]);
        }
        return solve(0,0,intervals_modified,starting).idx;
    }
};