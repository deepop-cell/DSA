class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(k + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            int min_diff=0;//a,b mai se ek ko uthae dusre ke equal kardia
            int max_diff = max({a, b, k - a, k - b});
            int current_diff = abs(a - b);
            diff[0] += 2;
            diff[k + 1] -= 2;
            diff[min_diff] -= 1;
            diff[max_diff + 1] -=(-1);
            diff[current_diff] -= 1;
            diff[current_diff + 1] -=(-1);
        }
        int res = INT_MAX;
        int csum = 0;
        for (int target = 0; target <= k; target++) {
            csum += diff[target];
            res = min(res, csum);
        }

        return res;
    }
};