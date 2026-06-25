
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int id, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
            return 0;
        }
        
        vis[i][j] = true;
        grid[i][j] = id;

        int up    = dfs(grid, i - 1, j, vis, id, n);
        int down  = dfs(grid, i + 1, j, vis, id, n);
        int left  = dfs(grid, i, j - 1, vis, id, n);
        int right = dfs(grid, i, j + 1, vis, id, n);

        return 1 + up + down + left + right;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int unique_id = 2;
        unordered_map<int, int> mp;
        int maxar = 0;
        bool hasZero = false; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size = dfs(grid, i, j, vis, unique_id, n);
                    maxar = max(maxar, size);
                    mp[unique_id] = size;
                    unique_id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    hasZero = true; 
                    unordered_set<int> st;
                    
                    if (i - 1 >= 0 && grid[i - 1][j] != 0) st.insert(grid[i - 1][j]); 
                    if (i + 1 < n  && grid[i + 1][j] != 0) st.insert(grid[i + 1][j]); 
                    if (j - 1 >= 0 && grid[i][j - 1] != 0) st.insert(grid[i][j - 1]); 
                    if (j + 1 < n  && grid[i][j + 1] != 0) st.insert(grid[i][j + 1]); 

                    int overall_size = 1; 
                    for (auto &it : st) {
                        overall_size += mp[it];
                    }
                    maxar = max(maxar, overall_size);
                }
            }
        }
        
        return (!hasZero) ? n * n : maxar;
    }
};