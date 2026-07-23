class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1]; // Sort descending based on units per box
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int totalUnits = 0;
        for (auto& box : boxTypes) {
            int count = box[0];
            int unitsPerBox = box[1];
            if (truckSize >= count) {
                totalUnits += count * unitsPerBox;
                truckSize -= count;
            } else {
                totalUnits += truckSize * unitsPerBox;
                break; // Truck is full
            }
        }
        return totalUnits;
    }
};