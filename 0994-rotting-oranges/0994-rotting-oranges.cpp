class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
     int f=0;
     queue<pair<int,int>>q;
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
         if(grid[i][j]==2){
            q.push({i,j});
         }
         if(grid[i][j]==1){
            f++;
         }
        }
     }  
     if(f==0){
        return 0;
     }
     int time=0;
     while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(auto &dir:directions){
             int newr=r+dir[0];
             int newc=c+dir[1];
             if(newr<0 || newc<0 || newr>=grid.size() || newc>=grid[0].size() || grid[newr][newc]!=1){
                continue;
             }
             else{
                q.push({newr,newc});
            grid[newr][newc]=2;//sad gya hai 
            f--;
             }
            }
        }
        time++;
            if(f==0){
                return time;
            }
     } 
     return -1;
    }
};