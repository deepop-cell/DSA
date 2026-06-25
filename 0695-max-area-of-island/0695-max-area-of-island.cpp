class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis,  int n,int m) {
        if (i < 0 || i >= n || j < 0 || j >= m|| grid[i][j] == 0 || vis[i][j]) {
            return 0;
        }
        vis[i][j] = true;
        int up    = dfs(grid, i - 1, j, vis, n,m);
        int down  = dfs(grid, i + 1, j, vis, n,m);
        int left  = dfs(grid, i, j - 1, vis, n,m);
        int right = dfs(grid, i, j + 1, vis, n,m);

        return 1 + up + down + left + right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int maxar=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int size=dfs(grid,i,j,vis,n,m);
                    maxar=max(maxar,size);

                }
            }
        }
        return maxar;
    }
};