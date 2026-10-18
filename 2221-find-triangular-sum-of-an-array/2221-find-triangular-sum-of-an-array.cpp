class Solution {
public:
    int triangularSum(vector<int>& nums) {
    int n=nums.size();
    for(int i=n;i>=1;i--){
        vector<int>newnums(i-1);
        for(int j=0;j<i-1;j++){
            newnums[j]=(nums[j]+nums[j+1])%10;
        }
        nums.pop_back();
        nums=newnums;
    }
    return nums[0];
    }
};