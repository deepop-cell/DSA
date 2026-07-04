class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        map<int,long long>mp;
        long long result=INT_MIN;
        for(int i=0;i<n;i++){
            long long sum=nums[i];
            auto it=mp.upper_bound(nums[i]-i);
            if(it!=mp.begin()){
                //>=nums[i]-i. milgaya hai.
                it--;
                sum+=it->second;
                //entry bhi kardo

            }
            mp[nums[i]-i]=max(mp[nums[i]-i],sum);//jo bhi bada ho usko lnea hai.
            //entry ke baad hume wo nums[i]-i jiska value bada hia par sum chota hai wo useles hai use dlete krdo
            it=mp.upper_bound(nums[i]-i);
            while(it!=mp.end() && it->second<=sum){
                mp.erase(it++);
            }
            //ab useless delete ho gye hai 
            result=max(result,sum);
        }
     return result;
        }
};