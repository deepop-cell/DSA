class Solution {
public:
int dp[101];
bool vis[101];
bool isvalid(string x){
    if(x[0]=='0' && x.length()>=1){
        return false;
    }
    return true;
}
    int ways(string s,int i){
        if( i<s.length() && s[i]=='0'){
            return 0;
        }
        if(!isvalid(s.substr(0,i+1))){
            return 0;//no decding possible from here.
        }
        if(i==s.length()){
            return  1;//one way of ecoding is found;
        }
        if(i>s.length()){
            return 0;
        }
        if(vis[i]){
            return dp[i];
        }

        //now at this curr idx we have otpions, either to include curr and move ahead or to inlcude current 
        int include1=ways(s,i+1);//decode as one digit.
        //now befroe decoding as two digits we need a check.
        int num=stoi(s.substr(i,2));
        int include2=0;
        if(num<=26 && num>=1){
        include2=ways(s,i+2);
        }
        vis[i]=true;
        return dp[i]=include1+include2;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        return ways(s,0);
    }
};