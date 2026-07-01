class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int l=0;
        int r=0;
        int maxlen=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0){
                zero++;
            }
            while(zero>1){//while invalid.
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }//iske baad window valid ho jaygi
            maxlen=max(maxlen,r-l);

        }
        return maxlen;
    }
};