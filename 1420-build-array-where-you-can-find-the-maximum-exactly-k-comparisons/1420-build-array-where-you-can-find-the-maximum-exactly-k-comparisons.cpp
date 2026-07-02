class Solution {
public:
int dp[51][51][102];//due to doing +1 in max_val we changed  it from 101 to 102
const int MOD = 1e9 + 7;
int solve(int idx,int search_cost,int max_val,int n,int m,int k){
    if(idx==n){
        if(search_cost==k){
            return 1;//found one valid arrau
        }
        else{
            return 0;
        }
    }
    if(search_cost>k){
        return 0;//dont waste time exploring this path
    }
    if(dp[idx][search_cost][max_val+1]!=-1){//max_val +1  for handling the -1 cas (initially its -1)
        return dp[idx][search_cost][max_val+1];
    }
    long long result=0;
    for(int i=1;i<=m;i++){
        //exploring all the m options at the given index
        if(i>max_val){
            //bada number hai to search cost badhega 
        result =(result + solve(idx+1,search_cost+1,i,n,m,k)) % MOD;//update the search sot and max val and call fucntion for ahead 
        }
        else{
            //chota hai to search cost utna hee rhega
           result = (result + solve(idx+1,search_cost,max_val,n,m,k)) % MOD;
        }
    }
    return dp[idx][search_cost][max_val+1]=result %MOD;
}
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
       return  solve(0,0,-1,n,m,k);
    }
};