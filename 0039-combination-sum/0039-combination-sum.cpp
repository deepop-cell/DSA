class Solution {
public:
    void solve(int i,int sum,vector<int>&temp,vector<vector<int>>&res,vector<int>&c){
        if(sum==0){
            //matlab target sum achived.
            res.push_back(temp);
            return;//ab ho gya ye, iska recursive call band krdo.
        }
        if(i>=c.size()){
            //out of bounds aa  gye recursioon call ko band krdo..
            return;
        }
        //ab take or skip kro.
        int take=0;
        if(c[i]<=sum){
            //take wali branch
            temp.push_back(c[i]);//this could be leading to possible sum , so push it.
            solve(i,sum-c[i],temp,res,c);
            temp.pop_back();//backtracking..
        }
        //skip wali branch....
        solve(i+1,sum,temp,res,c);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,target,temp,res,c);
        return res;
    }
};