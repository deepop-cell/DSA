class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int n=nums.size();
      int l=0;
      int r=0;
      long long product=1;
      int  count=0;
      for(int r=0;r<n;r++){
    product=1LL*(product*nums[r]);
    while(product>=k){
        product=1LL*(product/nums[l]);
        l++;
    }
    //now we have a valid window and since its prpduct is  less than k then all of smaller ones ending at that will also have product less than k.
    count+=r-l+1;
      }  
      return count;
    }
};