class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
    int l=0;
    int r=0;
    int mn=INT_MAX;
    long long sum=0;
    for(r=0;r<n;r++){
    sum+=nums[r];
    while(sum>=target){
   mn=min(mn,r-l+1);
        sum-=nums[l];
        l++;
    }
     
    }
    if(mn==INT_MAX){
        return 0;
    }
    return mn;
    }
};