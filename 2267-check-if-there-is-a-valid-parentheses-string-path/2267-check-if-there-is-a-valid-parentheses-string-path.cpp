class Solution {
public:
bool dp[101][101][205];
bool vis[101][101][205];
    bool solve(int i,int j,stack<char>&st,int n,int m,vector<vector<char>>&grid,int bal){
        if(i==m-1 && j==n-1){
            if(st.empty() && bal==0){
                return true;
            }
            else{
                return false;
            }
        }
        if(vis[i][j][bal]){
            return dp[i][j][bal];
        }
        //now we have 2 options .
        //down.
        if(i+1<m){
            if(grid[i+1][j]==')'){
                if(!st.empty()){
                st.pop();
                if(solve(i+1,j,st,n,m,grid,bal-1)){
                    vis[i][j][bal]=true;
                    return dp[i][j][bal]=true;
                }
                st.push('(');
                }

            }
            else{
                st.push(grid[i+1][j]);
                if(solve(i+1,j,st,n,m,grid,bal+1)){
                    vis[i][j][bal]=true;
                    return dp[i][j][bal]=true;
                }
                st.pop();//backtracking
            }
        }
        //right
        if(j+1<n){
            if(grid[i][j+1]==')'){
                if(!st.empty()){
                st.pop();
                if(solve(i,j+1,st,n,m,grid,bal-1)){
                    vis[i][j][bal]=true;
                    return dp[i][j][bal]=true;
                }
                st.push('(');
                }
            }
            else{
                st.push(grid[i][j+1]);
                if(solve(i,j+1,st,n,m,grid,bal+1)){
                    vis[i][j][bal]=true;
                    return dp[i][j][bal]=true;
                }
                st.pop();
            }
        }
        vis[i][j][bal]=true;
        return dp[i][j][bal]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,false,sizeof(dp));
        memset(vis,false,sizeof(vis));
        int m=grid.size();
        int n=grid[0].size();
        stack<char>st;
        if(grid[0][0]==')'){
            return false;
        }
        st.push(grid[0][0]);
        return solve(0,0,st,n,m,grid,1);
    }
};