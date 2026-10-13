class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]*=(-1);
            }
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        long long ans=0;
        if(n%2==0){
        while(i<=j){
         ans+=1LL*nums[j]*nums[j]-1LL*nums[i]*nums[i];
         i++;
         j--;
        }
        }
        else{
            //odd hai to beech wala reh jaega na akele .
        while(i<j){
         ans+=1LL*nums[j]*nums[j]-1LL*nums[i]*nums[i];
         i++;
         j--;
        }
        ans+=1LL*nums[i]*nums[i];
        }
        return ans;
    }
};