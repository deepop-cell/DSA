class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      unordered_map<int,int>mp;
      for(int &x:nums){
        mp[x]++;
      }
        if(k==0){
            int cnt=0;
            for(auto &it:mp){
                if(it.second>1){
                    cnt++;
                }
            }
            return cnt;
        }
      int cnt=0;
      unordered_map<int,bool>vis;
      for(int i=0;i<nums.size();i++){
        int check=nums[i]+k;
        if(mp.find(check)!=mp.end() && !vis[check]){
            cnt++;
            vis[check]=true;
        }
      }  
      return cnt;
    }
};