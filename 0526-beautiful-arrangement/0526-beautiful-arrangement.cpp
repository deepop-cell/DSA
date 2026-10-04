class Solution {
public:
void solve(int i,vector<int>&nums,int &count){
    if(i==nums.size()){
        count++;
     return;
    }
    //now see permutation is just swapping .
    for(int j=i;j<nums.size();j++){
        swap(nums[j],nums[i]);
        if(nums[i]%(i+1)==0 || (i+1)%nums[i]==0){
        solve(i+1,nums,count);
        }
        swap(nums[i],nums[j]);
    }
}
    int countArrangement(int n) {
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        int count=0;
        solve(0,nums,count);
        return count;
    }
};