class Solution {
public:
int dp1[200001];
int dp2[200001];
int dp3[200001][3];
int dp4[200001][3];
int solve_odd(int i,vector<int>&nums){
    if(i==nums.size()){
        return 0;
    }
    if(dp1[i]!=-1){
        return dp1[i];
    }
    int take=0;
    if(nums[i]%2!=0){
    take=1+solve_odd(i+1,nums);
    }
    int skip=solve_odd(i+1,nums);
    return  dp1[i]=max(take,skip);
}
int solve_even(int i,vector<int>&nums){
    if(i==nums.size()){
        return 0;
    }
    if(dp2[i]!=-1){
        return dp2[i];
    }
    int take=0;
    if(nums[i]%2==0){
    take=1+solve_even(i+1,nums);
    }
    int skip=solve_even(i+1,nums);
    return  dp2[i]=max(take,skip);
}
int solve_alt1(int i,int prev,vector<int>&nums){
    if(i==nums.size()){
        return 0;
    }
    if(  dp3[i][prev+1]!=-1){
        return dp3[i][prev+1];
    }
    int take=0;
    if((prev==-1)&& (nums[i]%2==0) || prev%2!=nums[i]%2){
    take=1+solve_alt1(i+1,nums[i],nums);
    }
    int skip=solve_alt1(i+1,prev,nums);
    return dp3[i][prev+1]=max(take,skip);
}
int solve_alt2(int i,int prev,vector<int>&nums){
    if(i==nums.size()){
        return 0;
    }
    if(dp4[i][prev+1]!=-1){
        return dp4[i][prev+1];
    }
    int take=0;
    if((prev==-1)&& (nums[i]%2!=0) || prev%2!=nums[i]%2){
    take=1+solve_alt2(i+1,nums[i],nums);
    }
    int skip=solve_alt2(i+1,prev,nums);
    return dp4[i][prev+1]=max(take,skip);
}
    int maximumLength(vector<int>& nums) {
        //4 cases, odd,even .. or even,odd or odd,odd, or even,even
        //only parity matters.
        for(int i=0;i<nums.size();i++){
            nums[i]%=2;
        }
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        memset(dp3,-1,sizeof(dp3));
        memset(dp4,-1,sizeof(dp4));
        int len1=solve_odd(0,nums);
        int len2=solve_even(0,nums);
        int len3=solve_alt1(0,-1,nums);
        int len4=solve_alt2(0,-1,nums);
        return max({len1,len2,len3,len4});
    }
};