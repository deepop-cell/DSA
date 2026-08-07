class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        //we use concept of virtual index here.
        int i=0;
        int j=r*c-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int x=mid/c;
            int y=mid%c;
            if(matrix[x][y]==target){
                return true;
            }
            else if(matrix[x][y]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return false;
    }
};