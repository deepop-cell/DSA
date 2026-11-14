class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<long long>a;
        for(int i=0;i<nums.size();i++){
            long long csum=0;
            for(int j=i;j<nums.size();j++){
            csum+=nums[j];
            if(j-i+1<=r && j-i+1>=l && csum>0){
                a.push_back(csum);
            }
            
            }
        }
        sort(a.begin(),a.end());
        if(a.empty())return -1;
        return a[0];
    }
};