class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int l=0;
       int r=0;
       int maxlen=0;
       unordered_map<char,int>mp;
       for(r=0;r<s.size();r++){
        mp[s[r]]++;
        while(mp[s[r]]>1){//while invalid
        mp[s[l]]--;
        l++;
        }
        //now window is valid
        int currlen=r-l+1;
        maxlen=max(maxlen,currlen);
       }
       return maxlen;
    }
};