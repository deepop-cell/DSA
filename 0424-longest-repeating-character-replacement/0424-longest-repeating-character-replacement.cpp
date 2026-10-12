class Solution {
public:
int getmax(unordered_map<char,int>&mp){
    int mx=-1;
    for(auto &it:mp){
        mx=max(mx,it.second);
    }
    return mx;
}
    int characterReplacement(string s, int k) {
        //we needd to find largest window of k non equal elemtns.
        // non equal means size-mxfreq<=k ye condition hogi.
        int l=0;
        int r=0;
        unordered_map<char,int>mp;
        int mxfreq=0;
        int len=-1;
        for(r=0;r<s.length();r++){
            mp[s[r]]++;
            mxfreq=max(mxfreq,mp[s[r]]);
            while(r-l+1 -mxfreq>k){//while invalid.
                mp[s[l]]--;
                mxfreq=getmax(mp);
                l++;//shrinnking left until valid ban jae
            }
            //now we have a valid window.
            len=max(len,r-l+1);
        }
        return len;
    }
};