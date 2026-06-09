#include<iostream>
void rearrange(int arr[], int n){
 int even=0;
 int odd=1;
 int temp[n];
 for(int i=0;i<n;i++){
    if(arr[i]>0){
        temp[even]=arr[i];
        even+=2;
    }
    else{
        temp[odd]=arr[i];
        odd+=2;
    }
 }
 for(int i=0;i<n;i++){
    arr[i]=temp[i];
 }

}