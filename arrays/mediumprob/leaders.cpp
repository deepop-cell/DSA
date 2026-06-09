#include<iostream>
void leaders(int arr[], int n){
    int count=1;
    int temp[n];
    int max=arr[n-1];
    temp[0]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]>max){
            max=arr[i];
            temp[count]=max;
            count++;
        }
    }
    int i=0;
    int j=count-1;
    while(i<=j){
        int tp=temp[i];
        temp[i]=temp[j];
        temp[j]=tp;
        i++;
        j--;
    }
}