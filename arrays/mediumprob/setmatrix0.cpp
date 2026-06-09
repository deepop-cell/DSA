#include<iostream>
void setmatrixzero(int arr[][100], int n,int m){
    int row[m]={0};
    int col[n]={0};
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0){
                row[k]=i;
                col[k]=j;
                k++;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[row[i]][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[j][col[i]]=0;
        }
    }
}
