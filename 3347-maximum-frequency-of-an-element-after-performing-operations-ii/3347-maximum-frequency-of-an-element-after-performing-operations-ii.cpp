class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;
        map<int,int>diff;//this time use map ... only for update points and points in numsss..
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);
            diff[l]++;
            diff[r+1]--;
            diff[nums[i]]+=0;//isko 0 hee rkho abhi..
        }
        int csum=0;
        int result = 1;
        for(auto it=diff.begin();it!=diff.end();it++) {
            csum+=it->second;
            it->second=csum;
            int targetFreq=freq[it->first];
            int needConversion = it->second - targetFreq;
            int maxPossibleFreq = min(needConversion, numOperations);
            result = max(result, targetFreq + maxPossibleFreq);
        }
        return result;
    }
};