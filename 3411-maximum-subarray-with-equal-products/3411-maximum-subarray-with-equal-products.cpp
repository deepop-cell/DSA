class Solution {
public:
    int maxLength(vector<int>& nums) {
       int res=2;
       for(int i=0;i<nums.size();i++){
        long long prod=nums[i];
        long long gcdval=nums[i];
        long long lcval=nums[i];
        for(int j =i+1;j<nums.size();j++){
            prod=prod * 1LL * nums[j];
            gcdval=gcd(gcdval,nums[j]);
            lcval=lcm(lcval,nums[j]);
            if(prod>gcdval*lcval)break;
            if(prod==gcdval * lcval){
                res=max(res,j-i+1);
            }
        }
       } 
       return res;
    }
};