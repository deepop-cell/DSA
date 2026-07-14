class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxl = 1; 
        vector<vector<int>> dp(n, vector<int>(k + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int rem = 0; rem <= k; rem++) {
                for (int j = 0; j < i; j++) {
                    if (nums[i] == nums[j]) {
                        dp[i][rem] = max(dp[i][rem], dp[j][rem] + 1);
                    } 
                    else if (nums[i] != nums[j] && rem > 0) { 
                        dp[i][rem] = max(dp[i][rem], dp[j][rem - 1] + 1);
                    }
                }
                maxl = max(maxl, dp[i][rem]);
            }
        }
        return maxl;
    }
};