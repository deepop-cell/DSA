class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;//already blocked hai path
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;//new way of marking vis
        int dist=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                int r=it.first;
                int c=it.second;
                if(r==n-1 && c==n-1){
                    //we have reached
                    return dist;
                }
                //explore all neighbours that is 8 directions
                for(auto &dir:directions){
                    int new_r=r+dir[0];
                    int new_c=c+dir[1];
                    if(new_r<0 || new_r>=n || new_c<0 || new_c>=n ||  grid[new_r][new_c]==1){
                        continue;
                    }
                    else{
                        q.push({new_r,new_c});
                        grid[new_r][new_c]=1;
                    }
                }

            }
            dist++;
        }
        return -1;
    }
};