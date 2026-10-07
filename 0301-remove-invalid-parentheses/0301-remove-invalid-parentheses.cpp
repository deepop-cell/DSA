class Solution {
public: 
    bool valid(string &s){
        int bal=0;
        for(auto &ch:s){
            if(ch=='('){
                bal++;
            }
            else if(ch==')'){
                bal--;
            }
            if(bal<0){
                return false;
            }
        }
        return bal==0;
    }
    void solve(int i,string&temp,unordered_set<string>&res,string &s,int &mx){
        if(i>=s.length()){
            if(valid(temp)){
                if(temp.size()>mx){
                mx=(int)temp.size();
                res.clear();
                res.insert(temp);
                }
                else if(temp.size()==mx){
                    res.insert(temp);
                }
            }
            return;
        }
        //option to take or not take
        if(s[i]=='(' || s[i]==')'){
        temp.push_back(s[i]);
        solve(i+1,temp,res,s,mx);
        temp.pop_back();
        solve(i+1,temp,res,s,mx);  
        }
        else{
            temp.push_back(s[i]);
            solve(i+1,temp,res,s,mx);
            temp.pop_back();
        }

    }
    vector<string> removeInvalidParentheses(string s) {
        string temp="";
        unordered_set<string>res;
        int m=0;
        solve(0,temp,res,s,m);
        vector<string>ans(res.begin(),res.end());
        return ans;
    }
};