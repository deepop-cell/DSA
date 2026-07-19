class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>taken(26,false);
        vector<int>lastvis(26,-1);
        for(int i=0;i<s.length();i++){
            lastvis[s[i]-'a']=i;
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(taken[ch-'a']){
                //taken hai to skip kaardo.. element already present in the given string..
                continue;
            }
            //this hting is to maintain lexicographical order for the subseuquence.//
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