class Solution {
public:
    bool dfs(int r,int c,int pr,int pc,vector<vector<bool>>&vis,vector<vector<char>>&grid){
        vis[r][c]=true;
        if(r+1<grid.size() && grid[r+1][c]==grid[r][c]){
            if(vis[r+1][c]){
            if(pr!=r+1 || pc!=c){
            return true;
            }
            }
            else{
            if(dfs(r+1,c,r,c,vis,grid)){
                return true;
            }
            }
        }
        if(c+1<grid[0].size() && grid[r][c+1]==grid[r][c]){
            if(vis[r][c+1]){
            if(pr!=r || pc !=c+1){
            return true;
            }
            }
            else{
            if(dfs(r,c+1,r,c,vis,grid)){
                return true;
            }
            }
        }
        if(r>0 && grid[r-1][c]==grid[r][c]){
            if(vis[r-1][c]){
                if(pr!=r-1 || pc!=c){
            return true;
                }
            }
            else{
            if(dfs(r-1,c,r,c,vis,grid)){
                return true;
            }
            }
        }
        if(c>0 && grid[r][c-1]==grid[r][c]){
            if(vis[r][c-1]){
                if(pr!=r || pc!=c-1){
            return true;
                }
            }
            else{
            if(dfs(r,c-1,r,c,vis,grid)){
                return true;
            }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,vis,grid)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};