class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        //if i just store max frewuency then for sure the others will be less than k only, 
        int maxfreq=0;
        map<int,int>freq;//element-->freq;
        int left=0;
        int right=0;
        int size=0;
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            maxfreq=max(maxfreq,freq[nums[right]]);
            while(freq[nums[right]]>k){//while invalid.
                freq[nums[left]]--;
                left++;
            }
            //now we have a valid window.
            size=max(size,right-left+1);
        }
        return size;
    }
};