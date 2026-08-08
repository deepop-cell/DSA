class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //if we assign 0-->-1 and 1-->1 thn we need to find longest suabrray with sum =0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
            else{
                nums[i]=1;
            }
        }
        map<int,int>mp;//sum,index/
        mp[0]=-1;
        int bestlen=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum)!=mp.end()){
                //if this exact sum was found previosuly then subarray between curr idx and that index is surely a subarray with sum 0.
            bestlen=max(bestlen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return bestlen;
    }
};