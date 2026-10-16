class Solution {
public:
vector<vector<int>>directions={{1,2},{1,-2},{2,1},{2,-1},{-1,-2},{-2,-1},{-1,2},{-2,1}};
    bool dfs(int r,int c,vector<vector<int>>& grid,int moves,int final){
        if(grid[r][c]==final){
            //last tha .
            return true;
        }
        for(auto &dir:directions){
            int n_x=r+dir[0];
            int n_y=c+dir[1];
            if(n_x<0 || n_x>=grid.size() || n_y<0 || n_y>=grid[0].size() || grid[n_x][n_y]!=moves+1){
                continue;
            }
            else if(grid[n_x][n_y]==moves+1){
            if(dfs(n_x,n_y,grid,moves+1,final)){
                //agar ye true return krega . 
                return true;
            }
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int final=INT_MIN;
        int start_x,start_y;
        if(grid[0][0]!=0){
            return false;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                final=max(final,grid[i][j]);
                if(grid[i][j]==0){
                    start_x=i;
                    start_y=j;
                }
            }
        }
        return dfs(0,0,grid,0,final);
    }
};