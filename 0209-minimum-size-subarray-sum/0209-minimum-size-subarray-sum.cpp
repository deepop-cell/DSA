class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int minlen=INT_MAX;
        int sum=0;
        for(right=0;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                //while valid(since minimum chahiye).
                minlen=min(minlen,right-left+1);
                sum-=nums[left];
                left++;
                
            }

        }
        return (minlen==INT_MAX)? 0 : minlen;
    }
};