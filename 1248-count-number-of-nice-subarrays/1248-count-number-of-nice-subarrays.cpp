class Solution {
public:
    int fn(vector<int>&nums,int k){
                int l=0;
        int r=0;
        int oddcnt=0;
        int no=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]%2!=0){
                // odd no hai .
                oddcnt++;
            }
            while(oddcnt>k){
                if(nums[l]%2!=0){
                    oddcnt--;
                }
                l++;
            }
            //now this is a valid window. and agaar isme atmost k odd numbers hai to isse chote wale sabme bhi honge.
            no+=(r-l+1);
        }
        return no;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //exaclty k ke liye atmost k  - atmost(k-1).
return fn(nums,k)-fn(nums,k-1);
    }
};