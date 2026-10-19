class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<pair<int,int>>p;
        for(int i=0;i<nums.size();i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            if(p[i].first==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};