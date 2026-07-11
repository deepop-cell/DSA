class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int x : arr) {
            mp[x]++;
        }
        
        int max_lucky = -1;
        
        // Iterate through the map instead of the array
        // pair.first is the number, pair.second is its frequency
        for (auto const& [num, freq] : mp) {
            if (num == freq) {
                max_lucky = max(max_lucky, num);
            }
        }
        
        return max_lucky;
    }
};