class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        // we want subarray of lentght 2.
        int n=nums.size();
        unordered_map<long long,int>mp;
        int l=0;
        long long  sum=0;
        int r=1;
        sum+=nums[0]+nums[1];
        mp[sum]++;
        while(r+1<n){
        r++;
        sum+=nums[r];
        sum-=nums[l];
        l++;
        if(mp.find(sum)!=mp.end()){
            return true;
        }
        mp[sum]++;
        }
        return false;
    }
};