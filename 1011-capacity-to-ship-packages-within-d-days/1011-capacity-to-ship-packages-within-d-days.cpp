class Solution {
public:
    bool check(vector<int>& arr, int days, int cap){
        int count = 0;
        int sum = 0;

        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];

            if(sum > cap){
                count++;
                sum = arr[i];
            }
        }

        return (count + 1) <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(check(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};