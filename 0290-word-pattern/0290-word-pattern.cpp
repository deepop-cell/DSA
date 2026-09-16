class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int x=pattern.length();
        int y=0;
        for(char &ch:s){
            if(ch==' '){
                y++;
            }
        }
        if(x!=y+1){
            return false;
        }
        unordered_map<string,bool>vis;
      unordered_map<char,string>mp;
      int j=0;
      for(int i=0;i<pattern.size();i++){
        char ch=pattern[i];
        string temp="";
        while( j<s.length() && s[j]!=' '){
        temp.push_back(s[j]);
        j++;
        }
        if(mp.find(ch)!=mp.end()){
            if(mp[ch]!=temp){
                return false;
            }
        }
        else{
            if(vis[temp]){
                return false;
            }
            mp[ch]=temp;
            vis[temp]=true;
        }
        while(s[j]==' '){
            j++;
        }
      }  
      return true;
    }
};