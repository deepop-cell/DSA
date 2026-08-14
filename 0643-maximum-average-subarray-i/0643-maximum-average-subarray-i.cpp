#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long current_sum = 0;
        
        // Compute sum of first window of size k
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        
        long long max_sum = current_sum;
        
        // Slide the window across the rest of the array
        for (int i = k; i < nums.size(); i++) {
            current_sum += nums[i] - nums[i - k];
            max_sum = max(max_sum, current_sum);
        }
        
        // Cast to double at the very end
        return static_cast<double>(max_sum) / k;
    }
};