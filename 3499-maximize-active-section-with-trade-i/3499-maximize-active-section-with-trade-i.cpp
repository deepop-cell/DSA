class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initial_active = 0;
        for (char &ch : s) {
            if (ch == '1') {
                initial_active++;
            }
        }
        int n = s.length();
        vector<pair<int, int>> q(n);
        int r_c = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                r_c++;
                q[i].second = r_c;
            } else {
                q[i].second = r_c;
                if (i > 0 && s[i - 1] == '0') {
                    r_c = 0;
                }
            }
        }
        int l_c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                l_c++;
                q[i].first = l_c;
            } else {
                q[i].first = l_c;
                if (i < n - 1 && s[i + 1] == '0') {
                    l_c = 0;
                }
            }
        }
        int possible_conv = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1' && q[i].first != 0 && q[i].second != 0) {
                possible_conv = max(possible_conv, q[i].first + q[i].second);
            }
        }

        return initial_active + possible_conv;
    }
};