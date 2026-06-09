#include<iostream>
void move0toend(int arr[], int n){
    int temp[n];
    int i=0;
    int k=0;
    int count=0;
    while(1){
    if(i==n){
    break;
    }
    if(arr[i]!=0){
        temp[k]=arr[i];
        k++;
    }
    else{
    count++;
    }
    i++;


    }
    for(int j=0;j<count;j++){
        temp[k]=0;
        k++;
        
    }
    for(int a=0;a<n;a++){
        arr[a]=temp[a];
    }
}