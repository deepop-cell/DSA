
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> ans(num1.length() + num2.length(), 0);
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int multiply = (num1[i] - '0') * (num2[j] - '0');
                int sum = multiply + ans[i + j + 1];
                ans[i + j + 1] = sum % 10;
                ans[i + j] += sum / 10;
            }
        }
        // Skip leading zeros
        int k = 0;
        while (k < ans.size() && ans[k] == 0) {
            k++;
        }
        string res = "";
        for (int i = k; i < ans.size(); i++) {
            res += to_string(ans[i]);
        }
        return res;
    }
};