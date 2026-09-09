class Solution {
public:
    bool check(vector<int>&nums,int maxsum,int k){
        long long sum=0;
        long long partition=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>maxsum){
                partition++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return partition<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=0;
        for(int &x:nums){
            high+=x;
        }
        int ans=-1;
        while(low<=high){
            long long mid=(low)+(high-low)/2;
            if(check(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};