class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
      for(int bits=0;bits<=31;bits++){
        //traverse all the 32 bits and check how mauy are different
        int z=0;
        int o=0;
        for(int i=0;i<nums.size();i++){
            if((nums[i]&(1<<bits))!=0){
            ///bits bit is 1/
            o++;
            }
            else{
                z++;
            }
        }
        //now is bit pe .
        ans+=(o*z);
      }  
      return ans;
    }
};