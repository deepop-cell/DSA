class Solution {
public:
    void solve(int i,int sum,vector<int>&temp,vector<vector<int>>&res,vector<int>& c){
        if(sum==0){
        //manjil mil gai.
        res.push_back(temp);
        return;
        }
        if(i>=c.size() && sum!=0){
            return;
        }
        //ab skip aur take krte hai,.
        //*****take************8
        if(c[i]<=sum){
            //to take kr skte .
            temp.push_back(c[i]);
            solve(i+1,sum-c[i],temp,res,c);
            temp.pop_back();//backtracking...
        }
        //************skip************
        //skip wli branch...
        //but duplicates skip krne hai .. thereforre.
        int nextidx=i+1;
        while(nextidx<c.size() && c[i]==c[nextidx]){
            nextidx++;
        }
        solve(nextidx,sum,temp,res,c);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        sort(c.begin(),c.end());
        solve(0,target,temp,res,c);
        return res;
    }
};