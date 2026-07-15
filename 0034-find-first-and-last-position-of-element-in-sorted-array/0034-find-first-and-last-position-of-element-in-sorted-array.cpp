class Solution {
public:
    int lowerbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int lb = nums.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) {
                lb = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return lb;
    }

    int upperbound(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ub = nums.size();

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > target) {
                ub = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ub;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerbound(nums, target);

        if(first == nums.size() || nums[first] != target)
            return {-1, -1};

        int last = upperbound(nums, target) - 1;

        return {first, last};
    }
};