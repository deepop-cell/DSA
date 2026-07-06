class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    if(intervals.empty()){
        return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1]; // Bigger end comes first
            }
            return a[0] < b[0]; // Starting index ascending
        });
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            //check if covered with latest entry of result
            auto &current=intervals[i];
            auto&prev=result.back();
            if(current[1]<=prev[1] && current[0]>=prev[0]){
                //matlab covered hai.
                continue;
            }
            else{
                result.push_back(current);
            }
        }
    return result.size();
        
    }
};