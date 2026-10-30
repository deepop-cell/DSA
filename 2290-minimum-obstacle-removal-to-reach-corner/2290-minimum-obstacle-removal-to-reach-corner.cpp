class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
      //we can do dijkstra and find min edge weight .. 
      int row=grid.size();
      int col=grid[0].size();
      vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
      //isme hum nodes ka dist store krenge so basically just do didjktra 
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      dist[0][0]=0;
      pq.push({0,{0,0}});
      while(!pq.empty()){
       auto it=pq.top();
       pq.pop();
       int d=it.first;
       auto pos=it.second;
       int r=pos.first;
       int c=pos.second;
       for(auto &dir:directions){
        int nr=r+dir[0];
        int nc=c+dir[1];
        if(nr<0 || nc<0 || nr>=row || nc>=col ){
            continue;
        }
        else{
            //then we should visit it . 
            if(grid[nr][nc]==1){
                //obstacle hai to 2 weight hai edge ka .
                if(dist[nr][nc]>dist[r][c]+2){
                    dist[nr][nc]=d+2;
                    pq.push({d+2,{nr,nc}});
                }
            }
            else{
                // free space hai to distance 0 hai . 
                if(dist[nr][nc]>dist[r][c]){
                    dist[nr][nc]=dist[r][c]+0;
                    pq.push({d,{nr,nc}});
                }
            }
        }
       }
      } 
      return dist[row-1][col-1]/2; 
    }
};