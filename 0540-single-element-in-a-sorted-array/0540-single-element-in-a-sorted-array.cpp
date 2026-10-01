class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int x=0;
      for(int &n:nums){
        x^=n;
      }  
      return x;
    }
};