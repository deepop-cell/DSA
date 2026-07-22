class Solution {
public:
int dp1[1001][1001];
int dp2[1001][1001];

    int solve_child2(int i, int j,vector<vector<int>>& fruits,int n){
        if(i>=n || j<0 || j>=n){
            return -1e9;//return a very small value so that max ignores it.
        }
        if(i==n-1 && j==n-1){
            return fruits[i][j];
        }
        //cntraints for child2.
        if(i>j || i==j){
            return -1e9;
        }
        if(dp1[i][j]!=-1){
            return dp1[i][j];
        }
        int path1=solve_child2(i+1,j-1,fruits,n);
        int path2=solve_child2(i+1,j,fruits,n);
        int path3=solve_child2(i+1,j+1,fruits,n);
        return dp1[i][j]=fruits[i][j]+max({path1,path2,path3});
    }
    int solve_child3(int i, int j,vector<vector<int>>& fruits,int n){
        if(i<0 || j>=n || i>=n){
            return -1e9;//return a very small value so that max ignores it.
        }
        if(i==n-1 && j==n-1){
            return fruits[i][j];
        }
        //cntraints for child2.
        if(i<j || i==j){
            return -1e9;
        }
        if(dp2[i][j]!=-1){
            return dp2[i][j];
        }
        int path1=solve_child3(i,j+1,fruits,n);
        int path2=solve_child3(i+1,j+1,fruits,n);
        int path3=solve_child3(i-1,j+1,fruits,n);
        return  dp2[i][j]= fruits[i][j]+max({path1,path2,path3});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    ans+=fruits[i][j];
                    fruits[i][j]=0;
                }
            }
        }//child 1 can only move diagnpolly so collecting the fruits and marking 0 along the diagonal..
        int c2=solve_child2(0,n-1,fruits,n);
        int c3=solve_child3(n-1,0,fruits,n);
        ans+=c2+c3;
        return ans;
    }
};