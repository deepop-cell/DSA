class Solution {
public:
    long long countCommas(long long n) {

        long long ans = 0;

        if (n >= 1000) {
            if (n < 1000000)
                return n - 999;

            ans += 999000;
        }

        if (n >= 1000000) {
            if (n < 1000000000)
                return ans + 2 * (n - 1000000 + 1);

            ans += 999000000LL * 2;
        }

        if (n >= 1000000000) {
            if (n < 1000000000000LL)
                return ans + 3 * (n - 1000000000LL + 1);

            ans += 999000000000LL * 3;
        }

        if (n >= 1000000000000LL) {
            if (n < 1000000000000000LL)
                return ans + 4 * (n - 1000000000000LL + 1);

            ans += 999000000000000LL * 4;
        }

        if (n == 1000000000000000LL) {
            ans += 5;
        }

        return ans;
    }
};