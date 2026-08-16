class Solution {
public:

    void solve(int open_count,int close_count,vector<string>&temp,string &res,int n){
        if(open_count==n && close_count==n){
            temp.push_back(res);
            return;
        }
        //now we have choice to open or close a bracket.
        if(close_count<open_count){
            res+=')';
            solve(open_count,close_count+1,temp,res,n);
            res.pop_back();
        }
        if(open_count<n){
            res+='(';
            solve(open_count+1,close_count,temp,res,n);
            res.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>temp;
        string res="";
        solve(0,0,temp,res,n);
        return temp;
    }
};