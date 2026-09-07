class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
      unordered_map<int,vector<int>>mp;
      for(int i=0;i<nums.size();i++){
       mp[nums[i]].push_back(i);
      }  
      //now iterate over queries.
      vector<int>ans;
      for(auto&q:queries){
        int x=nums[q];
        int k=mp[x].size();
        if(mp[x].size()==1){
             ans.push_back(-1);
        }
        else{
            int idx=lower_bound(mp[x].begin(),mp[x].end(),q)-mp[x].begin();
            int next=mp[x][(idx+1)%k];
            int prev=mp[x][(idx-1+k)%k];
            int d1=(next-q+n)%n;
            int d2=(q-prev+n)%n;
            ans.push_back(min(d1,d2));
        }
        }
      return ans;
    }
};