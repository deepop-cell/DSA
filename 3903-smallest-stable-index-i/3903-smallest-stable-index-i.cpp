class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>maxi(n);
        int mx=nums[0];
        maxi[0]=nums[0];
        for(int i=1;i<n;i++){
            mx=max(mx,nums[i]);
            maxi[i]=mx;
        }
        vector<int>mini(n);
        mini[n-1]=nums[n-1];
        int mn=nums[n-1];
        for(int i=n-2;i>=0;i--){
          mn=min(mn,nums[i]);
          mini[i]=mn;
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k){
                return i;
            }
        }
        return -1;
    }
};