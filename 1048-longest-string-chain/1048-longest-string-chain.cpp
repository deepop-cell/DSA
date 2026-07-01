class Solution {
public:
static bool myFunction(string &word1,string&word2){
    return word1.length()<word2.length();
}
int dp[1001][1001];
bool ispred(string &a,string &b){
    int n=a.length();
    int m=b.length();//ye chota wala hai
    if(m>=n || n-m!=1){
        return false;
    }
    int i=0;
    int j=0;
    while(i<m && j<n){
        if(a[j]==b[i]){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    return i==m;
}
int solve(int idx,int prev,vector<string>&words){
    if(idx>=words.size()){
        return 0;
    }
    int take=0;
    if(dp[idx][prev+1]!=-1){
        //prev+1 taki initial -1 ki wjh se wo array mai -1 index na dhoodnhe
        return dp[idx][prev+1];
    }
    //ab take kar skte hai ya  nahi wo check krlete hai
    if(prev==-1 || ispred(words[idx],words[prev])){
        //then take kr skte ho
        take=1+solve(idx+1,idx,words);
    }
    int skip=solve(idx+1,prev,words);
    return dp[idx][prev+1]=max(skip,take);
}
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),myFunction); //sort by lenght.
        return solve(0,-1,words);
    }
};