class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));
        if(m==1){
            for(int j=0;j<n;j++){
                grid[0][j]='.';
            }
             return grid;
        }
        if(n==1){
            for(int i=0;i<m;i++){
                grid[i][0]='.';
            }
            return grid;
        }
        grid[0][0]='.';
        grid[0][1]='.';
        for(int i=1;i<m;i++){
            grid[i][1]='.';
        }
        for(int j=2;j<n;j++){
            grid[m-1][j]='.';
        }
        return grid;
    }
};