class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(auto &ch:s){
            if(ch=='('){
                st.push(ch);
            }
            else if(ch==')' && !st.empty() && st.top()=='('){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        return st.size();
    }
};