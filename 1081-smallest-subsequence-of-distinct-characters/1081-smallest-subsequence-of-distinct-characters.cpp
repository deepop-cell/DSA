class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        vector<bool>taken(26,false);
        vector<int>lastvis(26,-1);
        for(int i=0;i<n;i++){
            lastvis[s[i]-'a']=i;
        }
        //now make a string where u will make a subsequence..
        string ans="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(taken[s[i]-'a']){
                continue;//skip if already taken this element in the subsequence,..
            }
            //now for lexicographcal order of subseuqeucne do this,
            while(!ans.empty() && ans.back()>ch && lastvis[ans.back()-'a']>i){
                taken[ans.back()-'a']=false;
                ans.pop_back();
            }
            //ab u can take this current element safely by maintaining lexicorgpahic order and no repeating characters..
            ans.push_back(ch);
            //ab dal rhe ho subsequence mai to mark vis bhi to kardo bhai sath hee sath
            taken[ch-'a']=true;
        }
        return ans;
    }
};