class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            ans+=mat[i][i];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(i+j==n-1){//anti DIAGONAL
                    ans+=mat[i][j];
                }
            }
        }
        return ans;
        
    }
};