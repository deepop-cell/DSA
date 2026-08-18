class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxel=-1;
        if(k==1 ){
            auto it=mp.begin();
            while(it!=mp.end()){
                if(it->first>maxel && it->second==1){
                    maxel=it->first;
                }

                   it++;
            }
            return maxel;
        }
        else if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        else{
            int c1=nums[0];
            int c2=nums[n-1];
            if(mp[c1]==1 && mp[c2]==1){
                return (c1>c2)?c1:c2;
            }
            else{
                if(mp[c1]==1){
                    return c1;
                }
                else if(mp[c2]==1){
                    return c2;
                }
                else{
                    return -1;
                }
            }
        }
    }
};