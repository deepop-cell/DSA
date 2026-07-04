class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       //patience sorting
       int n=nums.size();
       vector<int>sorted;
       for(int i=0;i<n;i++){
        auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]);
        if(it==sorted.end()){
            //means no element found which is greater than or equal to nums i so make new ll
            sorted.push_back(nums[i]);
        }
        else{
            //found the lower bound
            *it=nums[i];//replace the top
        }
       }
       return sorted.size();

    }
};