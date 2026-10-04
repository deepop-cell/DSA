class Solution {
public:
unordered_map<long long ,long  long>dp;
   long long solve(long long n){
    if(n==1){
        return 0;
    }
    if(dp.find(n)!=dp.end()){
        return dp[n];
    }
    long long option1=LLONG_MAX;
    if(n%2==0){
        option1=1+solve(n/2);
    }
    long long option2=LLONG_MAX;
    long long option3=LLONG_MAX;
    if(n%2!=0){
        option2=1+solve(n+1);
        option3=1+solve(n-1);
    }
    return dp[n]=min({option1,option2,option3});

   }
    int integerReplacement(int n) {
        return solve(n);
    }
};