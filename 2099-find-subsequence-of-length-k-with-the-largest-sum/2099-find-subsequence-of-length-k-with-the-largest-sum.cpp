class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<pair<int,int>>ans;
        while(k>0){
            ans.push_back({pq.top().second,pq.top().first});
            pq.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
        vector<int>q;
        for(auto &it:ans){
            q.push_back(it.second);
        }
        return q;
    }
};