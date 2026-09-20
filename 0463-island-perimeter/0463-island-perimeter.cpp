class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    //means its a land . 
                    int cnt=0;
                    if(i+1==rows){
                        cnt++;
                    }
                    if(i==0){
                        cnt++;
                    }
                    if(j+1==cols){
                        cnt++;
                    }
                    if(j==0){
                        cnt++;
                    }
                    if(i+1<rows && grid[i+1][j]==0){
                        cnt++;
                    }
                    if( j+1<cols && grid[i][j+1]==0){
                        cnt++;
                    }
                    if(i>0 && grid[i-1][j]==0){
                        cnt++;
                    }
                    if( j>0 && grid[i][j-1]==0){
                        cnt++;
                    }
                    perimeter+=cnt;
                }
            }
        }
        return perimeter;
    }
};