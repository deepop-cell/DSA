class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];//fixing this 
            //ab baki pe 2 pointer laga do.
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                 int totalsum= x+nums[j]+nums[k];
                if(totalsum<target){
                    if(target-totalsum<diff){
                        ans=totalsum;
                        diff=target-totalsum;
                    }
                    j++;
                }
                else if(totalsum>target){
                    if(totalsum-target<diff){
                        ans=totalsum;
                        diff=totalsum-target;
                    }
                    k--;
                }
                else{
                    //equal to target aa gya.
                    return target;
                }
            }
        }
        return ans;
    }
};