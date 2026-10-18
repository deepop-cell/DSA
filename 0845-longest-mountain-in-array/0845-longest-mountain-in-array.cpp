class Solution {
public:
   int longest(int idx,vector<int>&nums){
    int n=nums.size();
        int l=idx;
        int r=idx;
        while(l>0 && nums[l-1]<nums[l]){
            l--;
        }
        while(r+1<n && nums[r+1]<nums[r]){
            r++;
        }
        if(r==l || r==idx || l==idx){
            return 0;
        }
        return r-l+1;
   }
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        //humein potential peaks dekhni hai .
        vector<int>peaks;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]){
                //i is peak 
                peaks.push_back(i);
            }
        }
        int mxlen=0;
        for(int i=0;i<peaks.size();i++){
            int curr=peaks[i];
            int len=longest(curr,nums);
            mxlen=max(mxlen,len);
        }
        return mxlen;
       
    }
};