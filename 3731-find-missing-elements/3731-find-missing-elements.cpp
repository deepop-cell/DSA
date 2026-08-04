class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        map<int,int>mp;
        for(int &x:nums){
            mp[x]++;
        }
        //now check from 1 to n.
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        vector<int>res;
        for(int i=mn;i<=mx;i++){
            if(mp.find(i)==mp.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};