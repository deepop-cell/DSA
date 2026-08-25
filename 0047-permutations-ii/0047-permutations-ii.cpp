class Solution {
public:
    void solve(int i,set<vector<int>>&res,vector<int>&nums){
        if(i==nums.size()){
            res.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(i+1,res,nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        solve(0,st,nums);
        //now res  is filled.
        return vector<vector<int>>(st.begin(),st.end());

        
        
    }
};