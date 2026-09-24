class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        //manhattan dist is essentially dist found by bfs baically so its the biggest hint here ki hume bfs use krna chiye.
        //start multi source bfs from all land cells .
        int n=grid.size();
        int lc=0;
        int wc=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                //its land 
                q.push({i,j});
                lc++;
            }
            else{
                wc++;
            }
            }
        }
        if(lc==n*n || wc==n*n){
            return -1;
        }
        //now start bfs 
        int dist=0;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                int r=it.first;
                int c=it.second;
                q.pop();
                for(auto &dir:directions){
                    int new_r=r+dir[0];
                    int new_c=c+dir[1];
                    if(new_r<0 || new_r>=n || new_c<0 || new_c>=n){
                        ///out of bounds bahar aa gye matrix ke
                        continue;
                    }
                    if(!vis[new_r][new_c]){
                        q.push({new_r,new_c});
                        vis[new_r][new_c]=true;
                    }
                }

            }
            if(!q.empty()){
                dist++;
            }
        }
        return dist;
    }
};