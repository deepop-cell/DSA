class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        int currstreak=0;
        int total=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                currstreak++;
                total+=currstreak;
            }
            else{
                currstreak=0;
            }
        }
        return total;
    }
};