class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<int> prefixsum(n, 0);
        int csum = 0;
        for(int i = 0; i < n; i++) {
            csum = (csum + (s[i] - '0')) % MOD;
            prefixsum[i] = csum;
        }
        int zero = 0;
        vector<int> no_of_zeroes(n, 0);//iska matlab hai no of non zero elements till current index i.
        for(int i = 0; i < n; i++) {
            if(s[i] - '0' != 0) { 
                zero++;
            }
            no_of_zeroes[i] = zero;
        }
        // ab digits wala banalo.
        vector<int> digits(n, 0);
        long long j = 0; 
        for(int i = 0; i < n; i++) {
            if(s[i] - '0' != 0) {
                digits[i] = (j * 10 + (s[i] - '0')) % MOD;
            }
            else {
                digits[i] = j;
            }
            j = digits[i];
        }
        vector<int> result;
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int sum = (prefixsum[r] - (l > 0 ? prefixsum[l - 1] : 0) + MOD) % MOD;
            int k = no_of_zeroes[r] - (l > 0 ? no_of_zeroes[l - 1] : 0);
            long long base = (l > 0 ? digits[l - 1] : 0);
            int x = (digits[r] - (base * pow10[k]) % MOD + MOD) % MOD;
            result.push_back((1ll * x * sum) % MOD);
        }
        return result;
    }
};