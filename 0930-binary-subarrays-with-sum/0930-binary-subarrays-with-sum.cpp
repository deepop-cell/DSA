class Solution {
public://we can do this with sliding window also but cleaner way is hashmapn and prefix sum.
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int>mp;
        int sum=0;
        mp[0]=1;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-goal)!=mp.end()){
                count+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return count;
    }
};