class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int &x:nums){
            mp[x]++;
        }
        int j=k;
        while(1){
            if(mp.find(j)==mp.end()){
                return j;
            }
            j+=k;
        }
        return 0;
    }
};