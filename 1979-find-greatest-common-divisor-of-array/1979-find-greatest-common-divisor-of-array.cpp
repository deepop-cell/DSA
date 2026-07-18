class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max_el=INT_MIN;
        int min_el=INT_MAX;
        for(int i=0;i<nums.size();i++){
            max_el=max(max_el,nums[i]);
            min_el=min(min_el,nums[i]);
        }
        return gcd(max_el,min_el);
    }
};