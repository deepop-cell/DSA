#include<iostream>
void rotatematrix(int arr[][10000],int n){
    //first transpose
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    //then reverse each row.
    for(int i=0;i<n;i++){
        int j=0;
        int k=n-1;
        while(j<=k){
            int tp=arr[i][j];
            arr[i][j]=arr[i][k];
            arr[i][k]=tp;
            j++;
            k--;
        }
    }
}