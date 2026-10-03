class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
       stack<pair<char,int>>st;
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            st.push({s[i],i});
        }
        else if(s[i]==')' && !st.empty() && st.top().first=='('){
            st.pop();
        }
        else if(s[i]==')'){
            st.push({s[i],i});
        }
       } 
       //jo bhi stack mai last mai bach rha h mereko wo remove krna hai 
       unordered_map<int,int>mp;
       while(!st.empty()){
        auto it=st.top();
        st.pop();
        mp[it.second]++;
       }
       string ans="";
       for(int i=0;i<n;i++){
        if(mp.find(i)==mp.end()){
                    ans+=s[i];
        }
       }
       return ans;
    }
};