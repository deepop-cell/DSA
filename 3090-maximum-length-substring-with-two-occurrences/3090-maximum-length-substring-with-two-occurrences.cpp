class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        //we can do this with slidign window,
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        int maxfreq=-1;
        int maxlen=-1;
        for(int right=0;right<n;right++){
            mp[s[right]-'a']++;
            maxfreq=max(maxfreq,mp[s[right]-'a']);
            while(mp[s[right]-'a']>2){
                //while invalid 
                mp[s[left]-'a']--;
                left++;
        //shrink left.

        }
        //now we have a valid wiondpw
        //update len
        maxlen=max(maxlen,right-left+1);  
        }
        return maxlen;  
    }
};