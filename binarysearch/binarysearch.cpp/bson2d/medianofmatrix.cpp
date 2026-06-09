#include<iostream>
int median(int matrix[][10000000], int r,int c){
    int medianpos=(r*c)/2;
    int low=matrix[0][0];
    int high=matrix[0][c-1];
    for(int i=1;i<r;i++){
        if(matrix[i][0]<low){
            low=matrix[i][0];
        }
    }
    for(int i=1;i<r;i++){
        if(matrix[i][c-1]>high){
            high=matrix[i][c-1];
        }
    }
        int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]<=mid){
                    count++;
                }
            }
        }
        if(count>medianpos){
            high=mid-1;
            ans=mid;

        }
        else{
            low=mid+1;
        }
    }
    return ans;
}