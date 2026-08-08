class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int sum=0;
        mp[sum]++;//i e m[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=((sum%k)+k)%k;//to handle neg sum remainder topo
            if(mp.find(rem)!=mp.end()){
                //means same remiander was found previosuly also.
                count+=mp[rem];
            }
            mp[rem]++;
        }
        return count;
    }
};