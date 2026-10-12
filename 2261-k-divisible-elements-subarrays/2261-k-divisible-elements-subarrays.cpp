class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int l=0;
        int r=0;
        int cnt=0;
        int ans=0;
        set<vector<int>>subarrays;
        for(r=0;r<nums.size();r++){
            if(nums[r]%p==0){
                cnt++;
            }
            while(cnt>k){
                //shrink left/
                if(nums[l]%p==0){
                    cnt--;
                }
                l++;
            }
            //now we have a valid window of atmost k divisible by p.
            vector<int>a;
            for(int i=r;i>=l;i--){//always count subarrays eding at r.
                a.push_back(nums[i]);
                vector<int>t(a.begin(),a.end());
                reverse(t.begin(),t.end());
                subarrays.insert(t);
            }
        }
        return subarrays.size();
    }
};