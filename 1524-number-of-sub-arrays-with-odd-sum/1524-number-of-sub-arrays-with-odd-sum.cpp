class Solution {
public:
int mod=1e9+7;
    int numOfSubarrays(vector<int>& nums) {
        int evens=0;
        int odds=0;
        int csum=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            if(csum%2==0){
                ans=(ans+odds)%mod;
            }
            else{
                ans=(ans +(evens)+1)%mod;
            }
            if(csum%2==0){
                evens++;
            }
            else{
                odds++;
            }

        }
        return ans%mod;
    }
};