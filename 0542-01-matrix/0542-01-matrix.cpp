class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
      vector<vector<int>>dist(m,vector<int>(n,-1));
      queue<pair<int,int>>q;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                dist[i][j]=0;
                q.push({i,j});
            }
        }
      }  
      while(!q.empty()){
        auto it=q.front();
        q.pop();
        int r=it.first;
        int c=it.second;
        for(auto &dir:directions){
            int newr=r+dir[0];
            int newc=c+dir[1];
            if(newr<0 || newc<0 || newr>=m || newc>=n || mat[newr][newc]!=1){
                continue;
            }
            q.push({newr,newc});
            dist[newr][newc]=dist[r][c]+1;
            mat[newr][newc]=0;
        }
      }
      return dist;
    }
};