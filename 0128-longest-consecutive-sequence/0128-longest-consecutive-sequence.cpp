class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int len = 1;
        int best = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                continue;
            }
            else if(nums[i] == nums[i - 1] + 1) {
                len++;
            }
            else {
                best=max(best,len);
                len = 1;
            }
        }
        best=max(best,len);

        return best;
    }
};