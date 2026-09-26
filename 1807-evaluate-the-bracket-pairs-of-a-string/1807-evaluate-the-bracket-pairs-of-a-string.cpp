class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &ch:knowledge){
            string a=ch[0];
            string b=ch[1];
            mp[a]=b;
        }
        string ans="";
        //now traverse in the string .
        for(int i=0;i<s.length();i++){
            if(s[i]!='(' && s[i]!=')'  ){
              ans+=s[i];              
            }
            if(s[i]=='('){
                int j=i+1;
                string key="";
                while(s[j]!=')'){
                key+=s[j];
                    j++;
                }
                i=j;
                ///now j is at the end of that beracekt.
                if(mp.find(key)==mp.end()){
                    //means not present //
                    ans+='?';
                }
                else{
                ans+=mp[key];
                }

            }
        }
        return ans;
    }
};