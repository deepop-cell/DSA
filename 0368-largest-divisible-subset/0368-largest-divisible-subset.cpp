class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int end=-1;
        int mx=0;
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                  //we can inlcude this one.
                  if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                    if(dp[i]>mx){
                        mx=dp[i];
                        end=i;
                    }
                  }
                }
            }
        }
        if(end==-1){
            return {nums[0]};
        }
        vector<int>ans;
        int k=end;
        while(parent[k]!=-1){
         ans.push_back(nums[k]);
         k=parent[k];
        }
        ans.push_back(nums[k]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};