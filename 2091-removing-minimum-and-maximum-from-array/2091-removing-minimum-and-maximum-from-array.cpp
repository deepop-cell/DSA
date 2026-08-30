class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minidx=-1;
        int maxidx=-1;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){
                mn=nums[i];
                minidx=i;
            }
            if(nums[i]>mx){
                mx=nums[i];
                maxidx=i;
            }
        }
        //try all cases.
        int ans=INT_MAX;
        //option 1 is delete from front.
        int option1=1+max(minidx,maxidx);
        //option 2 is delete from end/
        int option2=max(n-minidx,n-maxidx);
        //option 3 is front and back simultanesouly.
        int option3=min(1+minidx + n-maxidx,1+maxidx + n-minidx);
        return min({option1,option2,option3});
    }
};