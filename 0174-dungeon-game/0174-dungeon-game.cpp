class Solution {
public:
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& dungeon, int m, int n) {
        // Base Case 1: Out of bounds
        if (i >= m || j >= n) {
            return 1e9; // Large positive number so min() ignores invalid paths
        }

        // Base Case 2: Destination cell
        if (i == m - 1 && j == n - 1) {
            return (dungeon[i][j] > 0) ? 1 : 1 - dungeon[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, dungeon, m, n);
        int down = solve(i + 1, j, dungeon, m, n);

        int minHealthNeeded = min(right, down) - dungeon[i][j];

        // If cell gives so much health that required health drops <= 0, 
        // knight still needs at least 1 HP to stay alive.
        return dp[i][j] = (minHealthNeeded <= 0) ? 1 : minHealthNeeded;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        int m = dungeon.size();    // rows
        int n = dungeon[0].size(); // cols
        
        return solve(0, 0, dungeon, m, n);
    }
};