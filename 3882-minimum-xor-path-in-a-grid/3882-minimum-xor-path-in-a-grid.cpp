class Solution {
public:
  //here normal dp template fails becase  xor operations arent monotonic.
vector<vector<vector<bool>>> vis;
    void solve(int i,int j,vector<vector<int>>& grid,int &mn,int curr_xor){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            //end aa gya hai . 
            mn=min(mn,curr_xor);
            return;
        }
        if(vis[i][j][curr_xor]){
            //this path is already explored and iska ans min mai update hho chuka hoga so no use of again exploring it .
            return;
        }
        vis[i][j][curr_xor]=true;
        if(j+1<grid[0].size()){
        solve(i,j+1,grid,mn,(curr_xor^grid[i][j+1]));
        }
        if(i+1<grid.size()){
        solve(i+1,j,grid,mn,(curr_xor^grid[i+1][j]));
        }
    }
    int minCost(vector<vector<int>>& grid) {
     int mn=INT_MAX;
     int curr_xor=grid[0][0];
     int rows=grid.size();
     int cols=grid[0].size();
    vis.assign(rows, vector<vector<bool>>(cols, vector<bool>(1024, false)));
     solve(0,0,grid,mn,curr_xor);
     return mn;
    }
};