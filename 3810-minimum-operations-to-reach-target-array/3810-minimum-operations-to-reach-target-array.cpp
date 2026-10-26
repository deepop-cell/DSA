class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int op=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(nums[i]!=target[i]){
                if(mp.find(nums[i])==mp.end()){
                    //not in map 
                mp[nums[i]]++;
                }
            }
        }
        return (int)mp.size();
    }
};