class Solution {
public:
double dp[101][101][104];
    double solve(int i,int k,int prev,vector<int>&nums,vector<int>&prefix){
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(k==0){
            int start=(prev>0)?prefix[prev-1]:0;
            int x=(prev==-1)?0:prev;
           return (prefix[n-1]-start)/(double)(n-x);
        }
        if(i>=nums.size()){
            return -1e9;
        }
        if(dp[i][k][prev+1]!=-1){
            return dp[i][k][prev+1];
        }
        //now we have choice either parition here or not,
        double cut=-1e9;
        if(i>0){
        int l=(prev>0)?prefix[prev-1]:0;
        int x=(prev==-1)?0:prev;
        cut=(prefix[i-1]-l)/(double)(i-x) + solve(i+1,k-1,i,nums,prefix);
        }
        double nocut=solve(i+1,k,prev,nums,prefix);
        return  dp[i][k][prev+1]=max(cut,nocut);
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n);
        int csum=0;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            prefix[i]=csum;
        }
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                for(int k=0;k<104;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(0,k-1,-1,nums,prefix);
    }
};