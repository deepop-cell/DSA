class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k=-1;//isme all bits set hote hai initiallty
        //agar ealready sorted hai to return 0 krna hau 
        bool f=true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<nums[i]){
                f=false;
                break;
            }
        }
        if(f){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                //ye correct pos par nahi hai 
                k = (k & nums[i]);
            }
        }
        return k;
    }
};