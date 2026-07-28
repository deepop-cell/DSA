class Solution {
public:
int dp[100001][3];//0 for prev=-1 and 1 and 2 index for 0 and 1.
    int solve(int i,int prev,string&s){
        if(i==s.length()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int flip=1e9;
        int skip=1e9;
        if(s[i]=='0'){
            if(prev==0 || prev==-1){
                //u can flip or not flip.
                flip=1+solve(i+1,1,s);
                skip=solve(i+1,0,s);
            }
            else{
                //prev==1.
                //here u have to flip , because u need increasing monotone.
                flip=1+solve(i+1,1,s);
            }
        }
        else{
        //curr is 1.
        if(prev==1){
            //then u cant flip.
            skip=solve(i+1,1,s);
        }
        else{
            //prev is 0, u can flip or noflip.
            flip=1+solve(i+1,0,s);
            skip=solve(i+1,1,s);
        }
        }
        return dp[i][prev+1]=min(flip,skip);
    }
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,s);
    }
};