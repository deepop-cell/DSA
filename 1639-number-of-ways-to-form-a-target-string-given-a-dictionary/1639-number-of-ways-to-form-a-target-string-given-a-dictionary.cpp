class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1005][1005];
    long long solve(int i, int j, vector<string>& words, string& target, vector<vector<int>>& freq) {
        if (i >= target.length()) {
            return 1; // Successfully formed target
        }
        if (j >= words[0].length()) {
            return 0; 
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        long long take = 0;
        int count = freq[target[i] - 'a'][j];
        if (count > 0) {
            take = (1LL*count *solve(i+1,j+1,words,target,freq)) % MOD;
        }
        long long skip = solve(i, j + 1, words, target,freq);
        return dp[i][j] = (take + skip) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        int k = words[0].length();
        // freq[char][col]
        vector<vector<int>> freq(26, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < words.size(); j++) {
                freq[words[j][i] - 'a'][i]++;
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, words, target, freq);
    }
};