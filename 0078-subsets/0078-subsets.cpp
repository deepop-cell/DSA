class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res){
        if(i==nums.size()){
            //aanth a gya ab push karlo
            res.push_back(temp);
            return;
        }
    //*****************TAKE**********
    //no condition for take sop u can do anyways..
    temp.push_back(nums[i]);
    solve(i+1,nums,temp,res);
    temp.pop_back();//backtrakcing..


    //********SKIP********
    solve(i+1,nums,temp,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ///subsets discover krne hai ,. for each element we have a choice to either include it in our subset or not. so kanpsack,,
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,nums,temp,res);
        return res;
    }
};