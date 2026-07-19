class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>taken(26,false); 
        vector<int>lastvis(26,-1);
        for(int i=0;i<s.length();i++){
            lastvis[s[i]-'a']=i;
        }
        //now start  making ans
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(taken[ch-'a']){
                continue;
            }
            while(!ans.empty() && ans.back()>ch && lastvis[ans.back()-'a']>i){
                taken[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(ch);
            taken[ch-'a']=true;
        }
        return ans;
    }
};