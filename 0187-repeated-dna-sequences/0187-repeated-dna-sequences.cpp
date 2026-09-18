class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        if(n<10){
            return {};
        }
        unordered_map<string,int>mp;
        int l=0;
        int r=9;
        string temp="";
        for(int i=l;i<=r;i++){
            temp+=s[i];
        }
        mp[temp]++;
        while(r<n){
            r++;
            l++;
           string x="";
            for(int i=l;i<=r;i++){
                x+=s[i];
            }
            //now we have our string 
            mp[x]++;
        }
        vector<string>ans;
        auto it=mp.begin();
        while(it!=mp.end()){
            if(it->second>1){
                ans.push_back(it->first);
            }
            it++;
        }
        return ans;

    }
};