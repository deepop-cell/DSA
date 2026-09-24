class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      //simple bfs
      int dist=0;
      int m=maze.size();
      int n=maze[0].size();
      queue<pair<int,int>>q;
      int x=entrance[0];
      int y=entrance[1];
      q.push({x,y});
      vector<vector<bool>>vis(m,vector<bool>(n,false));
      vis[x][y]=true;
      bool found=false;
      while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            if((r==m-1 || c==n-1 || r==0 || c==0) && !(r==x && c==y)){
                //boundary aa gyi .
                found=true;
                break;
            }
            //explore all neighbours.
            for(auto &dir:directions){
                int new_r=r+dir[0];
                int new_c=c+dir[1];
                if(new_r<0 || new_r>=m || new_c<0 || new_c>=n|| vis[new_r][new_c] || maze[new_r][new_c]=='+'){
                    continue;//out of bounds hai ya to vis hai ya to wall hai
                }
                else{
                    q.push({new_r,new_c});
                    vis[new_r][new_c]=true;
                }

            }
        }
        if(found){
         return dist;
        }
        dist++;
      }  
      return -1;
    }
};