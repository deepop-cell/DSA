
class Solution {
public:
    bool dp[2001][2001];
    bool vis[2001][2001];
    bool solve(int i, int k, vector<int>& stones) {
        //  Reached the last stone!
        if (i == stones.size() - 1) {
            return true;
        }
        if (vis[i][k]) {
            return dp[i][k];
        }
        vis[i][k] = true;
        for (int jump = k - 1; jump <= k + 1; jump++) {
            if (jump <= 0) continue; // Jump size must be > 0
            int target_pos = stones[i] + jump;
            auto it = lower_bound(stones.begin() + i + 1, stones.end(), target_pos);
            // Verify if a stone actually exists at target_pos
            if (it != stones.end() && *it == target_pos) {
                int next_idx = it - stones.begin();
                if (solve(next_idx, jump, stones)) {
                    return dp[i][k] = true; // abhi hee true aa gya to aage kyu solve krna hai bhai , abhi hee true return krdo na
                }
            }
        }
        return dp[i][k] = false;
    }
    bool canCross(vector<int>& stones) {
        //  The first jump MUST be 1 unit to position 1
        if (stones[1] != 1) return false;
        memset(dp, false, sizeof(dp));
        memset(vis, false, sizeof(vis));
        // Start from index 1 after making the first forced jump of k = 1
        return solve(1, 1, stones);
    }
};