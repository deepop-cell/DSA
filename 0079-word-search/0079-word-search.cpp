class Solution {
public:  
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    bool solve(int r,int c, int i,vector<vector<char>>& grid,string &word,vector<vector<bool>>&vis){
        if(i==word.length()-1){
            return true;
        }
        for(auto &dir:directions){
            int newx=r+dir[0];
            int newy=c+dir[1];
            if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size() || grid[newx][newy]!=word[i+1] || vis[newx][newy]){
                //out of bounds ya to mismatch ya to already visited
                continue;
            }
            else{
                vis[newx][newy]=true;
                if(solve(newx,newy,i+1,grid,word,vis))return true; 
                vis[newx][newy]=false;//backtracking      
            }
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    if(solve(i,j,0,board,word,vis))return true;
                    vis[i][j]=false;
                }
            }
        }
        return false;
        
    }
};