class Solution {
public:
int dp[20001];
int solve(int idx,vector<int>&values,vector<int>&points){
    if(idx>=values.size()){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    //say u r taking
    int take=0;
    if( idx+1<values.size() && values[idx+1]==values[idx]+1){//manlo next wala adjancent hai to skip it
     take=points[idx]+solve(idx+2,values,points);
    }
    else{
     take=points[idx]+solve(idx+1,values,points);
    }
    //skip krne ke lie
    int skip=solve(idx+1,values,points);
    return dp[idx]=max(skip,take);
}
    int deleteAndEarn(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
    map<int,int>mp;
    for(int x:nums){
        mp[x]++;
    }
    for(auto &it:mp){
        it.second=it.first*it.second;
    }//make points table
    vector<int>values;
    vector<int>points;
    for(auto &it:mp){
        values.push_back(it.first);
        points.push_back( it.second);
    }
    return solve(0,values,points);        
    }
};