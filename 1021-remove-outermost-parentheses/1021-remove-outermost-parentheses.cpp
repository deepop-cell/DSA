class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal=0;
        unordered_map<int,int>pos;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(bal==0){
                    pos[i]++;
                }
                bal++;
            }
            else{
                if(bal==1){
                    pos[i]++;
                }
                bal--;
            }
        }
        //open fir end aise hoga .
        string ans="";
        for(int i=0;i<s.length();i++){
            if(pos.find(i)!=pos.end()){
                continue;
            }
            ans+=s[i];
        }
        return ans;

    }
};