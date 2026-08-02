class Solution {
public:
int dp[50001][2];
bool vis[50001][2];
;    int solveforalice(int i,int person,vector<int>&stoneValue){
        if(i>=stoneValue.size()){
            return 0;
        }
        if(vis[i][person]){
            return dp[i][person];
        }
        int stones=0;
        int res=(person==1)?INT_MIN:INT_MAX;
        for(int j=1;j<=3;j++){
            if(person==1){//a;lice ki bari hai
            if(j+i-1<stoneValue.size()){
            stones+=stoneValue[j+i-1];
            }
            res=max(res,stones+solveforalice(j+i,0,stoneValue));//apne mia best dega
            }
            else{//bob ki baari hai.
            res=min(res,solveforalice(j+i,1,stoneValue));//opponent bhi best dega to waha se worst(min) expect krega.
            }
        }
        vis[i][person]=true;
        return dp[i][person]=res;
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