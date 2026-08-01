class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftsum(n);
        vector<int>rightsum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            leftsum[i]=sum;
            sum+=nums[i];
        }
        int x=0;
        for(int i=n-1;i>=0;i--){
            rightsum[i]=x;
            x+=nums[i];
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(abs(leftsum[i]-rightsum[i]));
        }
        return res;        
    }
};