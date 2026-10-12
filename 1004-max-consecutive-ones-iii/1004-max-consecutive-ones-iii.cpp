class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //we need to find the longest subarray with atmost k 0s.
        int l=0;
        int r=0;
        int ans=-1;
        int cnt=0;
        for(r=0;r<nums.size();r++){
        if(nums[r]==0){
            cnt++;
        }
        while(cnt>k){
            //while invalid shrink left.
            if(nums[l]==0){
                cnt--;
            }
            l++;
        }
        //now we have a valid wiondow.
    ans=max(ans,r-l+1);
        }
        return ans;
    }
};