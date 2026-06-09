#include<iostream>
void rotatearraybyk(int arr[], int k,int n){
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[(i+k)%n];
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
        
    }
}
