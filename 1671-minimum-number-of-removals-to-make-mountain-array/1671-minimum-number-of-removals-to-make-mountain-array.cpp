class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        //it is basvially LDS +LIS .
        int n=nums.size(); 
        vector<int>LIS(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    LIS[i]=max(LIS[i],LIS[j]+1);
                }
            }
        }
        //now Longest decreasing subsequence starting at index i .
        vector<int>LDS(n,1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i]){
                    LDS[i]=max(LDS[i],LDS[j]+1);
                }
            }
        }
        int largestpeak=-1;
        for(int i=0;i<n;i++){
            if(LIS[i]<=1 || LDS[i]<=1){
                continue;
            }
            largestpeak=max(largestpeak,LDS[i]+LIS[i]-1);
        }
        return n-largestpeak;
    }
};