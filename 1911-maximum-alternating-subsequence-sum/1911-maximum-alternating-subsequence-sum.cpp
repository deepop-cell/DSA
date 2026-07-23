class Solution {
public:
    typedef long long ll;
    ll dp[100001][2];

    ll solve(int idx, vector<int>& nums, bool flag) {
        // Base case: out of bounds
        if (idx == nums.size()) {
            return 0;
        }

        // Return memoized result if already calculated
        if (dp[idx][flag] != -1) {
            return dp[idx][flag];
        }

        // Option 1: Skip the current element
        ll skip = solve(idx + 1, nums, flag);

        // Option 2: Take the current element
        ll val = nums[idx];
        if (!flag) {
            val = -val; // Subtract if we are at an odd position in our alternating sequence
        }
        ll take = val + solve(idx + 1, nums, !flag);

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, true); // true indicates we need an addition (+) next
    }
};