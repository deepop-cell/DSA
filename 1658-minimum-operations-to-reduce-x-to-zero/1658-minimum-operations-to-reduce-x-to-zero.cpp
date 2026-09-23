class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //we eneed to find the longest subarray whose sum is equal to sum-x;
        int sum=0;
        for(int &x:nums){
            sum+=x;
        }
        int target=sum-x;
        if(target<0){
            return -1;
        }
        int l=0;
        int r=0;
        long long csum=0;
        int maxlen=-1;
        for(r=0;r<nums.size();r++){
        csum+=nums[r];
        while(csum>target){
            //shrink left.
            csum-=nums[l];
            l++;
        }
        //now we have a valid window/
        if(csum==target){
        maxlen=max(maxlen,r-l+1);
        }
        }
        if(maxlen==-1){
            return -1;
        }
        return nums.size()-maxlen;
    }
};