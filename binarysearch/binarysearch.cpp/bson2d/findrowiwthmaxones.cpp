#include<iostream>
int row_with_max_ones(int matrix[][100000],int rows, int cols){
    int bestans=0;
    int rowindex=-1;
    for(int i=0;i<rows;i++){
        int low=0;
        int ans=0;
        int high=cols-1;
        int x=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[i][mid]<1){
                low=mid+1;
            }
            else if(matrix[i][mid]==1){
                x=mid;
                ans=cols-x;
                if(ans>bestans){
                    bestans=ans;
                    rowindex=i;
                }
                high=mid-1;//for finding if there is any 1 at leftside(leftmost position_).
            }
        }
    }
    return rowindex;
}