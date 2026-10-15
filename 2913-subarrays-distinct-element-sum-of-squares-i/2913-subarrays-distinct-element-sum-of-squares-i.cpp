class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>st;//i se start hone waali subarray 
            for(int j=i;j<n;j++){
            st.insert(nums[j]);
            int x=(int)st.size();
    ans+=(x*x);
            }
        }
        return ans;
    }
};