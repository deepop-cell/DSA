class Solution {
public:
    void solve(string s,int i,vector<string>&currpart,vector<vector<bool>>&dp,vector<vector<string>>&res){
        //base case..
        if(i==s.length()){
            //successful partition done.
            res.push_back(currpart);
        }
        for(int j=i;j<s.length();j++){
            if(dp[i][j]){
                //agar pal hai to partition kar skte ho,...
                currpart.push_back(s.substr(i,j-i+1));
                solve(s,j+1,currpart,dp,res);
                currpart.pop_back();//backtracking......ab hum alag partiion explorekrenge to uske pehle isko delete krna padega na,...
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        //state defn dp[i][j]=true means substr from i to j is  a palindrome..
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++){
            for(int i=0;i<n-L+1;i++){
                int j=i+L-1;
                if(L==1){
                    dp[i][j]=true;
                }
                else if(L==2){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                else{
                    //L>2...
                    if(s[i]==s[j] && dp[i+1][j-1]){
                        dp[i][j]=true;
                    }
                }
            }
        }    
        vector<string>currpart;
        vector<vector<string>>res;
        solve(s,0,currpart,dp,res);
        return res;
    }
};