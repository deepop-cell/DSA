class Solution {
public:
bool dp[101][2000];
bool vis[101][2000];
    bool solve(int i,int open,string &s){
        if(i==s.length()){
            if(open==0){
                return true;
            }
            return false;
        }
        if(open<0){
            return false;
        }
        if(vis[i][open]){
            return dp[i][open];
        }
        //3 options 
        if(s[i]!='*'){
            if(s[i]=='('){
                return solve(i+1,open+1,s);
            }
            else{
                return solve(i+1,open-1,s);
            }
        }
        else{
            //we have 3 options ,
            bool o1=solve(i+1,open+1,s);
            if(o1){
                vis[i][open]=true;
                return dp[i][open]=true;
            }
            bool o2=solve(i+1,open-1,s);
            if(o2){
                vis[i][open]=true;
                return dp[i][open]=true;
            }
            bool o3=solve(i+1,open,s);
            if(o3){
                vis[i][open]=true;
                return dp[i][open]=true;
            }
        }
        vis[i][open]=true;
        return dp[i][open]=false;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};