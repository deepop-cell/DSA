class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
      int l=0;
      int r=0;
      unordered_map<int,int>mp;
      int len=-1;
      int mxfreq=0;
      for(r=0;r<nums.size();r++){
      mp[nums[r]]++;
      mxfreq=max(mxfreq,mp[nums[r]]);
      int size=r-l+1;
      while(r-l+1-mxfreq>k){//while invalid
        ///shrink kro left ko 
        mp[nums[l]]--;
        l++;
      }
    len=max(len,r-l+1);
      }  
        return mxfreq;
    }
};