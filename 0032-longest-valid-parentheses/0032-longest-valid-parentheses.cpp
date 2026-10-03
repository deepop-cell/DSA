class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            if(open==close){
             maxlen=max(maxlen,open+close);
            }
            else if(close>open){
                //invalid hai bc
                close=0;
                open=0;
            }
        }
        //now do right  to left traversal.
        int o=0;
        int c=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='('){
                o++;
            }
            else{
                c++;
            }
            if(o==c){
                maxlen=max(maxlen,o+c);
            }
            else if(o>c){
                //invalud ho gya reset kro
                o=0;
                c=0;

            }
        }
        return maxlen;
    }
};