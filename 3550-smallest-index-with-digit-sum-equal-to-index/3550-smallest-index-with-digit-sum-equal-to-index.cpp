class Solution {
public:
    int digitsum(int n){
        int temp=n;
        int sum=0;
        while(temp>0){
            sum+=(temp%10);
            temp/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digitsum(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};