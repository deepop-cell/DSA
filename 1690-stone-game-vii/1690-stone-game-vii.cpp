class Solution {
public:
int dp[1002][1002];//note that sum is not a state because for a given l to r sum i sfixed.
    int solve(int i , int j , int sum , vector<int>&stones){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take_i=solve(i+1,j,sum-stones[i],stones);//opponenet adv if i take i
        int take_j=solve(i,j-1,sum-stones[j],stones);//opponnents advantage if i  take j
        //we return the max diff. 
        //sum-takenone - leftpick/rightpick
        return dp[i][j]=max(sum-stones[i]-take_i,sum-stones[j]-take_j);
    }
    int stoneGameVII(vector<int>& stones){
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(int &x:stones){
            sum+=x;
        }
        int n=stones.size();
        return solve(0,n-1,sum,stones);
    }
};