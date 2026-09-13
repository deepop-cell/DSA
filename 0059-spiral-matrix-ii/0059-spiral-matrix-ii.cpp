class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>>matrix(n,vector<int>(n));
      int top=0;
      int bottom=n-1;
      int left=0;
      int right=n-1;
      int assign=1;
      while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
           matrix[top][j]= assign;
           assign++;
        }
        top++;
        for(int i=top;i<=bottom;i++){
        matrix[i][right]=assign;
        assign++;
        }
        right--;
        for(int j=right;j>=left;j--){
            matrix[bottom][j]=assign;
            assign++;
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            matrix[i][left]=assign;
            assign++;
        }
        left++;
      }  
      return matrix;
    }
};