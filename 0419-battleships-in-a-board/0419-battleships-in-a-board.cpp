class Solution {
public:
    void dfs(int r,int c,vector<vector<bool>>&vis,vector<vector<char>>&b){
        vis[r][c]=true;
        if(r+1<b.size() && b[r+1][c]==b[r][c] && !vis[r+1][c]){
            dfs(r+1,c,vis,b);
        }
        if(c+1<b[0].size() && b[r][c+1]==b[r][c] && !vis[r][c+1]){
            dfs(r,c+1,vis,b);
        }
        if(r>0 && b[r-1][c]==b[r][c] && !vis[r-1][c]){
            dfs(r-1,c,vis,b);
        }
        if(c>0 && b[r][c-1]==b[r][c] && !vis[r][c-1]){
            dfs(r,c-1,vis,b);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        int count=0;
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='X' && !vis[i][j]){
                    count++;
                    dfs(i,j,vis,board);
                }
            }
        }
        return count;
    }
};