class Solution {
public:
    int fn(int &n){
        int temp=n;
        int x=0;
        while(temp>0){
            x+=(temp%10);
            temp/=10;
        }
        return x;
    }
    int maximumSum(vector<int>& nums) {
      unordered_map<int,vector<long long> >mp;  
      int n=nums.size();
      for(int i=0;i<n;i++){
        int curr=nums[i];
        int sum=fn(curr);
        mp[sum].push_back(curr);
      }
      long long ans=-1;
      for(auto &it:mp){
        sort(it.second.begin(),it.second.end());
      }
      for(auto &it:mp){
        if(it.second.size()>=2){
            int sz=it.second.size();
            ans=max(ans,it.second[sz-1]+it.second[sz-2]);
        }
      }
      return ans;
    }
};