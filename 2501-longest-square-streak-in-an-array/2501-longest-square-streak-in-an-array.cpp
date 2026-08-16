class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // 1. O(1) lookup ke liye set me daal diya
        unordered_set<long long> st(nums.begin(), nums.end());
        int maxStreak = -1;

        for (int x : nums) {
            long long curr = x;
            int count = 0;

            // 2. Jab tak x, x^2, x^4 set me milte rahe, aage badhte raho
            while (st.count(curr)) {
                count++;
                curr = curr * curr; // agla square
                if (curr > 100000) break; // max constraint se bahar chala gaya
            }

            // 3. Problem kehti hai streak kam se kam 2 elements ki honi chahiye
            if (count >= 2) {
                maxStreak = max(maxStreak, count);
            }
        }

        return maxStreak;
    }
};