class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
      stack<pair<char,int>>st;
      vector<pair<int,int>>brackets;
      for(int i=0;i<n;i++){
       if(s[i]==')'){
        brackets.push_back({st.top().second,i});
         st.pop();
       }
       else if(s[i]=='('){
        st.push({'(',i});
       }
      }  
      //now reverse each pair of braces.f
      for(int i=0;i<brackets.size();i++){
        int start=brackets[i].first;
        int end=brackets[i].second;
        reverse(s.begin()+start+1,s.begin()+end);
      }
      string ans="";
      for(char &ch:s){
        if(ch=='(' || ch==')'){
            continue;
        }
        ans+=ch;
      }
      return ans;
    }
};