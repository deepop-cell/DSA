class Solution {
public:
    void solve(int open_c,int close_c,vector<string>&res,string&temp,int n){
        if(open_c==n && close_c==n){
            res.push_back(temp);
            return;
        }
        //w have choice , ya to close kro ya to open,
        if(open_c<n){
            temp+='(';
            solve(open_c+1,close_c,res,temp,n);
            temp.pop_back();
        }
        if(close_c<open_c){
            temp+=')';
            solve(open_c,close_c+1,res,temp,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp="";
        solve(0,0,res,temp,n);
        return res;
    }
};