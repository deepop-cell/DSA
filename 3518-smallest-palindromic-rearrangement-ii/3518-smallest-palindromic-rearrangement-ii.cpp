class Solution {
public:
    // Safe NCR calculation capped at limit to avoid signed long long overflow
    long long NCR(int n, int r, long long limit) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;

        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res > limit) {
                return limit; // Stop multiplying further if it exceeds limit!
            }
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();
        char mid = ' ';
        if (n % 2 != 0) {
            // n is odd.
            mid = s[(n / 2)];
        }
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        if (n % 2 == 1) {
            count[s[n / 2] - 'a']--; /// mid wala hum fix kr rhe hai(uska ek use hoga mid mai) to uske use nhi krenge half mai.
        }
        // half freq will be used to build half res
        for (int i = 0; i < 26; i++) {
            count[i] /= 2;
        }

        // --- PRE-CHECK TOTAL WAYS FOR HALF FREQUENCIES ---
        long long total_ways = 1;
        int total_letters = 0;
        for (int c = 0; c < 26; c++) {
            total_letters += count[c];
        }
        for (int c = 0; c < 26; c++) {
            if (count[c] > 0) {
                long long ncr_val = NCR(total_letters, count[c], k + 1);
                if (ncr_val > 0 && total_ways > (k + 1) / ncr_val) {
                    total_ways = k + 1;
                } else {
                    total_ways *= ncr_val;
                }
                total_letters -= count[c];
            }
        }
        if (total_ways < k) {
            return ""; // Not enough palindromes possible
        }

        string halfres = "";
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            // fixing indicies.
            for (int j = 0; j < 26; j++) {
                // for deciding which char to fix at the ith index.
                if (count[j] > 0) {
                    // current ko fix kr rhe .
                    count[j]--;
                    // count number of ways now.
                    long long ways = 1;
                    int letters = 0;
                    for (int c = 0; c < 26; c++) {
                        letters += count[c];
                    }
                    for (int c = 0; c < 26; c++) {
                        if (count[c] > 0) {
                            long long ncr_val = NCR(letters, count[c], k + 1);
                            if (ncr_val > 0 && ways > (k + 1) / ncr_val) {
                                ways = k + 1;
                            } else {
                                ways *= ncr_val;
                            }
                            letters -= count[c]; // itna pos use krlia.
                        }
                    }
                    if (ways >= k) {
                        // matlab we can fix this 
                        halfres.push_back(j + 'a');
                        // fix hogya to break ho jayo
                        break;
                    }
                    else {
                        k -= ways;
                        count[j]++; // we are not fixing j so undo its --.
                    }
                }
            }
        }
        string x = halfres;
        reverse(x.begin(), x.end());
        if (mid != ' ') {
            halfres.push_back(mid);
        }
        string ans = halfres + x;
        return ans;
    }
};