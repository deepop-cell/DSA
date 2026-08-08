class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        map<int,int>mp;
        mp[0]=1;
        for(int &x:nums){
            sum+=x;
            if(mp.find(sum-k)!=mp.end()){
                //means an oldsum such that sum-oldsum==k exissts, then wo jitni baar aya hoga past mai hum utne subarrays bana skte hai.
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};