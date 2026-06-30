class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int left=0;
       int right=0;
       int zeroes=0;
       int ans=0;
       for(right=0;right<nums.size();right++){
        if(nums[right]==0){
            zeroes++;
        }
        while(zeroes>k){//checks while(invalid)
            if(nums[left]==0){
                zeroes--;
            }
            left++;
        }
        //after this we have a valid subarray. so find its size.
        ans=max(ans,right-left+1);//r-l+1 is size of current window.


       }
       return ans;
    }
};