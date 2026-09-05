class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mx(n);
        vector<int>mn(n);
        int maximum=nums[0];
        int minimum=nums[n-1];
        mx[0]=nums[0];
        mn[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            maximum=max(maximum,nums[i]);
            mx[i]=maximum;
        }
        for(int i=n-2;i>=0;i--){
            minimum=min(minimum,nums[i]);
            mn[i]=minimum;
        }
        //now check.
        for(int i=0;i<n;i++){
            if(mx[i]-mn[i]<=k){
                return i;
            }
        }
        return -1;
    }
};