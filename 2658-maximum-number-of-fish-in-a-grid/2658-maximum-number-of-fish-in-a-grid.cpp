class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
int bfs(int r,int c , vector<vector<int>>&grid,int m,int n){
    queue<pair<int,int>>q;
    q.push({r,c});
    long long sum=grid[r][c];
    grid[r][c]=0;//style of marking vis/
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            for(auto&dir:directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                if(new_x<0 || new_x>=m || new_y<0 || new_y>=n || grid[new_x][new_y]==0){
                    continue;
                }
                else{
                    q.push({new_x,new_y});
                    sum+=grid[new_x][new_y];
                    grid[new_x][new_y]=0;//marking vis
                }
            }
            
        }
    }
    return sum;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int bestsum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    continue;
                }
                //treat it as staritng point 
                int currsum=bfs(i,j,grid,m,n);
                bestsum=max(currsum,bestsum);
            }
        }
        return bestsum;
    }
};