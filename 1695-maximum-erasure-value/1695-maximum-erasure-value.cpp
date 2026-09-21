class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int l=0;
      int r=0;
      int sum=0;
      int mxsum=-1;
      unordered_map<int,int>mp;
      for(r=0;r<nums.size();r++){
    mp[nums[r]]++;
    sum+=nums[r];
    while(mp[nums[r]]>1){
        mp[nums[l]]--;
        sum-=nums[l];
        l++;
    }
    mxsum=max(mxsum,sum);
      }  
      return mxsum;
    }
};