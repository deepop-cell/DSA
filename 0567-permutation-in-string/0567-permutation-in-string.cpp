class Solution {
public:
    bool checkmap(map<int,int>mp1,map<int,int>mp2){
        auto it1=mp1.begin();
        auto it2=mp2.begin();
        while(it1!=mp1.end() && it2!=mp2.end()){
            if(it1->first!=it2->first || it1->second !=it2->second){
                return false;
            }
            it1++;
            it2++;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        map<int,int>mp1;
        for(char &ch:s1){
            mp1[ch-'a']++;
        }

        int i=0;
        int r=s1.size()-1;
        map<int,int>mp2;
        for(int k=i;k<=r;k++){
            mp2[s2[k]-'a']++;
        }
        if(checkmap(mp1,mp2)){
            return true;
        }
        while(r<s2.size()){
            if(r+1<s2.size()){
             mp2[s2[r+1]-'a']++;
            mp2[s2[i]-'a']--;
            if(mp2[s2[i]-'a']==0){
                mp2.erase(s2[i]-'a');
            }
            }

            i++;
            r++;
            if(checkmap(mp1,mp2)){
                return true;
            }
        }
        return false;
    }
};