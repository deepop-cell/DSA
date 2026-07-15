
class Solution {
    int dp[205][205][205];
    int MOD = 1e9 + 7;

public:
    int solve(int i, vector<int>& nums, int gcd1, int gcd2) {
        if (i == nums.size()) {
            if (gcd1 != 0 && gcd2 != 0 && gcd1 == gcd2) {
                return 1;
            }
            return 0; 
        }
        if (dp[i][gcd1][gcd2] != -1) {
            return dp[i][gcd1][gcd2];
        }
        long long skip = solve(i + 1, nums, gcd1, gcd2);
        long long take1 = solve(i + 1, nums, std::gcd(gcd1, nums[i]), gcd2);
        long long take2 = solve(i + 1, nums, gcd1, std::gcd(gcd2, nums[i]));

        return dp[i][gcd1][gcd2] = (skip + take1 + take2) % MOD; 
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0, 0);
    }
};