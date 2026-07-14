class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long res=INT_MIN;
        map<int,long long>mp;//nums[i]-i-->sum..
        for(int i=0;i<nums.size();i++){
            long long sum=nums[i];
            auto it=mp.upper_bound(nums[i]-i);//ye nums[i]-i se just bada find krdega.
            if(it!=mp.begin()){
                it--;//ab nums[i]-i se chote ya barabar par khade hai hum.
                sum+=it->second;
            }
            mp[nums[i]-i]=max(sum,mp[nums[i]-i]);
            //ab useless values ko hatana hai .
            auto x=mp.upper_bound(nums[i]-i);
            while(x!=mp.end() && sum>=x->second){
                mp.erase(x++);
            }
            res=max(res,sum);
        }
        return res;
    }
};