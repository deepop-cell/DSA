class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int>res(n);
       int sum=0;
       res[0]=0;
       for(int i=0;i<n;i++){
        if(i!=0){
        if(i%2==0){
            res[i]=res[i/2];
        }
        else{
            res[i]=res[i/2]+1;
        }
        }
        if(res[i]==k){
            sum+=nums[i];
        }
       } 
       return sum;
    }
};