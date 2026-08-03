class Solution {
public:
int dp[50001][2];
bool vis[50001][2];
    int solveforalice(int i,int person, vector<int>&stoneValue){
        if(i>=stoneValue.size()){
            return 0;
        }
        //now we have choice of picking 1,2 or 3 elements starting from ith index.
        if(vis[i][person]){
            return dp[i][person];
        }
        int stones=0;
        int result=(person==1)?INT_MIN:INT_MAX;
        for(int j=1;j<=3;j++){
            if(person==1){//alice ki chance hai
            if(i+j-1<stoneValue.size()){
            stones+=stoneValue[i+j-1];
            }
            result=max(result,stones+solveforalice(i+j,0,stoneValue));
            }
            else{
                //bob ki chance hai 
                result=min(result,solveforalice(i+j,1,stoneValue));
            }
        }
        vis[i][person]=true;
        return  dp[i][person]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int p1=solveforalice(0,1,stoneValue);
        int total=0;
        for(int &x:stoneValue){
            total+=x;
        }
        int p2=total-p1;
        if(p1>p2){
            return "Alice";
        }
        else if(p1==p2){
            return "Tie";
        }
        else{
            return "Bob";
        }
    }
};