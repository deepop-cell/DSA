class Solution {
public:
    string minWindow(string s, string t) {
     vector<int>freq(128,0);
     for(auto &ch:t){
        freq[ch-'A']++;
     }   
     int l=0;
     int r=0;
     unordered_map<char,int>mp;
     for(auto &ch:t){
        mp[ch]++;
     }
     vector<int>window(128,0);
     int minlen=INT_MAX;
     int start=-1;
     int end=-1;
     int matches=0;
     for(r=0;r<s.length();r++){
        //include right in current window.
        ///(only count if itss in t so we can compare in 0(1)).
        if(mp.find(s[r])!=mp.end()){
        window[s[r]-'A']++;
        if(window[s[r]-'A']==freq[s[r]-'A']){
            matches++;
        }
        }
        while(matches==mp.size()){
            ///jab tk same hai . 
            end=r;
           if(r-l+1<minlen){
            minlen=r-l+1;
            start=l;
           }
            if(mp.find(s[l])!=mp.end()){
                window[s[l]-'A']--;
                if(window[s[l]-'A']<freq[s[l]-'A']){
                    matches--;
                }
            }
            l++;
        }


     }
     if(start==-1){
        return "";
     }
     return s.substr(start,minlen);
    }
};