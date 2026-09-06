class Solution {
public:
int m,n;
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
   bool solve(int i,int j,int k,string&word,vector<vector<char>>& board,vector<vector<bool>>&vis){
    if(k==word.length()){
        return true;
    }
    for(auto &dir:directions){
       int  i_n=(i+dir[0]);
       int  j_n=(j+dir[1]);
        if(i_n<0 || i_n>=m || j_n<0 || j_n>=n || vis[i_n][j_n]){
            continue;
        }
        if(board[i_n][j_n]==word[k]){
            vis[i_n][j_n]=true;
            bool x=solve(i_n,j_n,k+1,word,board,vis);
            if(x){
                return true;
            }
            vis[i_n][j_n]=false;//backtracking.
        }
    }
    return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;//starting ko mark kr rha hu .
                    if(solve(i,j,1,word,board,vis)){
                        return true;
                    }
                    vis[i][j]=false;//undo
                }
            }
        }
        return false;
    }
};