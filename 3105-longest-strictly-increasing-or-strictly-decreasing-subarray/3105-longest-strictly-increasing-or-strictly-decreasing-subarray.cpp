class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {\
    if(nums.size()==1){
        return 1;
    }
        int len=2;
        int maxlen=1;
        bool inc=true;
        if(nums[1]>nums[0])inc=true;
        if(nums[1]<nums[0])inc=false;
        if(nums[1]==nums[0])len=1;
        for(int i=1;i<nums.size()-1;i++){
            if(inc){
                if(nums[i+1]>nums[i]){
                    len++;
                }
                else{
                    maxlen=max(maxlen,len);
                    if(nums[i+1]==nums[i])len=1;
                    if(nums[i+1]<nums[i])len=2;
                    inc=false;
                }
            }
            else if(!inc){
                if(nums[i+1]<nums[i]){
                    len++;
                }
                else{
                    maxlen=max(maxlen,len);
                    if(nums[i+1]==nums[i])len=1;
                    if(nums[i+1]>nums[i])len=2;
                    inc=true;
                }
            }
        }
                    maxlen=max(maxlen,len);
                    len=1;
                    return maxlen;
    }
};