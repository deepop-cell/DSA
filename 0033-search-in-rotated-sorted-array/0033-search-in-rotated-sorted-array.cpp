class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target){
                return m;
            }
            //left half sorted..
            else if(nums[m]>=nums[l] ){
                if(target>=nums[l] && target<nums[m]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
            //right half sorted hai.
            else if(nums[m]<=nums[h]){
                if(target>nums[m] && target<=nums[h]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return -1;
    }
};