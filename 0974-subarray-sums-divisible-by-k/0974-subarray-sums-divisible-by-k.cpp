class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int csum=0;
        int cnt=0;
        int n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            int rem=(csum %k + k)%k;
            if(mp.find(rem)!=mp.end()){
                //ye remainder pehle b mila hai to abhise leke pehle tk ka subarray sum is div by k 
                cnt+=(mp[rem]);
            }
            mp[(rem)]++;
        }
        return cnt;
    }
};