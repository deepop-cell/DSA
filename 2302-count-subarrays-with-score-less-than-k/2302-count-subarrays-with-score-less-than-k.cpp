class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        if(k<=1){
            return 0;
        }
        int l=0;
        int r=0;
        int n=nums.size();
        long long cnt=0;
        long long sum=0;
        for(r=0;r<n;r++){
            sum+=nums[r];
            while(1ll*(sum)*(r-l+1)>=k){
                //tab tk shrink karo window ko.
                sum-=nums[l];
                l++;
            }
            //ab hmare paas ek valid window hai to iske jitne smaller subarrrays honge ending at r wo bhi valid honge kyuki unnka sum* len ka product bhi k se kam hoga
            cnt+=r-l+1;
        }
        return cnt;
        
    }
};