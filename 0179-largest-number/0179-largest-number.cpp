class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int x : nums) {
            strNums.push_back(to_string(x));
        }
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        if (strNums[0] == "0") {
            return "0";
        }
        string ans = "";
        for (const string &s : strNums) {
            ans += s;
        }
        return ans;
    }
};