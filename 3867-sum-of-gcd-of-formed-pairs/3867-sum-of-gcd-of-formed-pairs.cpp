class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixgcd[i]=std::gcd(nums[i],maxi);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long ans=0;
        int l=0;
        int r=n-1;
        while(l<r){
            ans+=gcd(prefixgcd[l],prefixgcd[r]);
            l++;
            r--;
        }
        return ans;

        
    }
};