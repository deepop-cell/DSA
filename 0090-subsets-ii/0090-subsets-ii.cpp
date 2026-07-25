class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        //*******************TAKE************
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,res);
        temp.pop_back();//backtrakcing.
        //**************SKIP*************
        //ab duplicate handling ke lie jisko skip kar rhe hai uske saree occurences ko skip krna pdega so we move i+1 upto where the eleent is same as skipped one
        int next_idx=i+1;
        while( next_idx<nums.size()&&nums[next_idx]==nums[i]){
            next_idx++;
        }
        solve(next_idx,nums,temp,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //this is again duplicate handling.
        //so first sort the array.
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>res;
        solve(0,nums,temp,res);
        return res;
    }
};