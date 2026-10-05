class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0;
        int depth=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
            }
            else{//ki hum ')' pe hai abhi
                if(s[i-1]=='('){
                    //we are at innermost nested parnethesesos
                    score+=(int)pow(2,depth-1);
                }
                depth--;
            }
        }
            return score;
    }
};