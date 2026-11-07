class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int currodd=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                currodd++;
            }
            if(mp.find(currodd-k)!=mp.end()){
                //means ki ye aya hai 
    ans+=mp[currodd-k];
            }
        mp[currodd]++;
        }
        return ans;
    }
};