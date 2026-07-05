class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>previdx(n,-1);
        int maxL=1;
        int maxl_idx=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]%nums[i]==0 || nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        previdx[i]=j;
                    }
                    if(dp[i]>maxL){
                        maxL=dp[i];
                        maxl_idx=i;
                    }


                }

            }
        }
        //now i have maxL index and previous index. 
        vector<int>result;
        int i=maxl_idx;
        while(previdx[i]!=-1){
            result.push_back(nums[i]);
            i=previdx[i];
        }
        //jab previdx[i]=-1 hai usko to push hee nhi kiya lol.
        result.push_back(nums[i]);
        reverse(result.begin(),result.end());
        return result;        
    }
};