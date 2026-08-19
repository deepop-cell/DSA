class Solution {
public:
    void solve(int openc,int closec,vector<string>&res,string&temp,int n){
        if(openc==n && closec==n){
            res.push_back(temp);
            return;
        }
        //now u have option  to close or open bracket.
        if(openc<n){
            temp+='(';
            solve(openc+1,closec,res,temp,n);
            temp.pop_back();//backtracking
        }
        if(openc>closec){
            temp+=')';
            solve(openc,closec+1,res,temp,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>res;
        solve(0,0,res,temp,n);
        return res;
    }
};