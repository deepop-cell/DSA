class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 != 0) return {};
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int &x : nums) {
            mp[x]++;
        }
        vector<int> res;
        res.reserve(n / 2);
        for (int i = 0; i < n; i++) {
            if (mp[nums[i]] == 0) continue;
            int search = nums[i] * 2;
            mp[nums[i]]--;
            if (mp[search] > 0) {
                res.push_back(nums[i]);
                mp[search]--;
            } else {
                return {}; 
            }
        }
        return res;
    }
};