class Solution {
public:
    bool checkwithDifferenceArrayteq(vector<int>&nums,vector<vector<int>>&queries,int index){
        vector<int>diff(nums.size(),0);
        for(int i=0;i<=index;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];
            diff[start]+=val;
            if(end+1<nums.size()){
                diff[end+1]-=val;
            }
        }
        int csum=0;
        for(int i=0;i<nums.size();i++){
            csum+=diff[i];
            diff[i]=csum;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>diff[i]){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int Q=queries.size();
        auto lambda=[](int x){
            return x==0;
        };
        if(all_of(begin(nums),end(nums),lambda)){
            return 0;//no operations required....
        }
       //for loop ke badle , do binary search
       int low=0;
       int high=Q-1;
       int ans=-1;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(checkwithDifferenceArrayteq(nums,queries,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            //try a bigger value bro
            low=mid+1;
        }
       }
        return (ans==-1)?-1:ans+1;
    }
};