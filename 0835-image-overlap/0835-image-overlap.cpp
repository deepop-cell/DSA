class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int row=1-n;row<n;row++){
            for(int col=1-n;col<n;col++){
            //trying all possible slides.'
            int row_shift=row;
            int col_shift=col;
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                int new_x=i+row_shift;
                int new_y=j+col_shift;
                if(new_x<0 || new_y>=n || new_y<0 || new_x>=n){
                    continue;
                }
                if(img1[i][j]==img2[new_x][new_y] && img1[i][j]==1){
                    count++;
                }
                ans=max(ans,count);
                }
            }
            }
        }
        return ans;
    }
};