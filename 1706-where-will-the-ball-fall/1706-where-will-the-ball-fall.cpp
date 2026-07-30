class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>answer(n);
        for(int j=0;j<n;j++){
            int i=0;
            int k=j;
            while(i>=0 && i<=m-1 && j>=0 && j<=n-1){
            if(( k+1<n && grid[i][k]==1 && grid[i][k+1]==-1) || ( k>0 && grid[i][k]==-1 && grid[i][k-1]==1)){
                //we aree stuck in v shape.
                answer[j]=-1;
                break;
            }
            if((k==0 && grid[i][k]==-1) || (k==n-1  && grid[i][k]==1)){
                answer[j]=-1;
                break;//stuck in wall.
            }
            //if not reached then move;
            if(grid[i][k]==1){
                i++;
                k++;
            }
            else{
                i++;
                k--;
            }
            if(i==m){
                //reached the bottom.
                answer[j]=k;
                break;
            }
            }
        }
        return answer;
    }
};