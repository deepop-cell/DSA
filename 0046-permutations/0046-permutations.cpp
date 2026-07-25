class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&res){
        if(idx==nums.size()){
            //means u have sucessfully formed one permuation of nums.
            res.push_back(nums);
            return;
        }
        //permuations is just swappping wali chiz so try swapping all pairs.
        for(int i=idx;i<nums.size();i++){//we start swapping from current pos because an element can stay at its own pos too
            swap(nums[i],nums[idx]);
            //recursive call for ahead for swappping.
            solve(idx+1,nums,res);
            swap(nums[idx],nums[i]);//revert it(backtracking wali chieez).
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(0,nums,res);
        return res;
        
    }
};