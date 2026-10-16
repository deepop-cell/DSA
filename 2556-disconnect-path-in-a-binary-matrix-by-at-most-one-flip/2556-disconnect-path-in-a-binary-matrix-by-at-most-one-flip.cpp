class Solution {
public:
bool fn(int i,int j,vector<vector<int>>&grid){
    if(i==grid.size()-1 && j==grid[0].size()-1){
        return true;
    }
    if(i>=grid.size() || j>=grid[0].size()){
        return false;
    }
    if(grid[i][j]==0){
        return false;
    }
    grid[i][j]=0;
    if(fn(i,j+1,grid)){
        return true;
    }
    if(fn(i+1,j,grid)){
        return true;
    }
    return false;
}
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        fn(0,0,grid);//mark a path as complete 0.
        grid[0][0]=1;
        return (!fn(0,0,grid));
    }
};