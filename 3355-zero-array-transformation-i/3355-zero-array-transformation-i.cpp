class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n,0);
        for(auto &x:queries){
            int start=x[0];
            int end=x[1];
            diff[start]+=1;
            if(end+1<n){
                diff[end+1]-=1;
            }
        }
        int csum=0;
        for(int i=0;i<n;i++){
            csum+=diff[i];
            diff[i]=csum;
        }
        //now chekc if u have made a zero array or not..
        for(int i=0;i<n;i++){
            if(nums[i]>diff[i]){
                return false;
            }
        }
        return true;
        
    }
};