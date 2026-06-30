class Solution {
public:
    int dp[101];
    int solve(vector<int>&nums,int i){
        if(i<0 || i>=nums.size()){
            return 0;//out of  bounds.
        }
        if(dp[i]!=-1){
            //means ki ye index ke liye solve ho rakha hai.
            return dp[i];
        }
        int steal=nums[i]+solve(nums,i+2);//ye ghar chura liya to iska jod lo aur agla ghar skip krke uska next churao
        int skip=solve(nums,i+1);//kuch nhi churaya to agla ghar churalo 
        return dp[i]=max(steal,skip);//returning value and storing in dp.
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        
        return solve(nums,0);        
    }
};