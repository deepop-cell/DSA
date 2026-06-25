class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int validsubarray=0;
        for(int i=0;i<n;i++){
            int targetcount=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    targetcount++;
                }
                int currlen=j-i+1;
                if(2*targetcount>currlen){
                    validsubarray++;
                }
            }
        }
     return validsubarray;   
    }
};