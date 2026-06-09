#include<iostream>
void leaders(int arr[], int n){
    int max=arr[n-1];
    arr[n-1] = -1;


    for(int i=n-2;i>=0;i--){
        int curr=arr[i];
        arr[i]=max;
        if(curr>max){
            max=curr;
        }
    }

}