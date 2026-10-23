class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int sum=0;
        int t=0;
        for(int &x:nums){
            t+=x;
        }

        for(int i=nums.size()-1;i>=0;
        i--){
            sum+=nums[i];
            ans.push_back(nums[i]);
            if(sum>t/2){
                break;
            }
        }
        return ans;
    }
};