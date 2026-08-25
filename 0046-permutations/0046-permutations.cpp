class Solution {
public:
    void solve(int i,vector<vector<int>>&res,vector<int>&nums){
        if(i==nums.size()){
            //we have formed one succesdsful permutation.
            res.push_back(nums);
            return;
        }
        ///perm is just swap of postiotn so try every 
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(i+1,res,nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(0,res,nums);
        return res;
    }
};