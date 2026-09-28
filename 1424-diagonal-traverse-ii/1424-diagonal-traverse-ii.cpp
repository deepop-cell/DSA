class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
       map<int,vector<int>>mp;
       int n=nums.size();
       int m=nums[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<nums[i].size();j++){
            mp[i+j].push_back(nums[i][j]);
        }
       } 
       for(auto &x:mp){
        reverse(x.second.begin(),x.second.end());
       }
       auto it=mp.begin();
       vector<int>ans;
       while(it!=mp.end()){
        int i=0;
        while(i<it->second.size()){
            ans.push_back(it->second[i]);
            i++;
        }
        it++;
       }
       return ans;
    }
};