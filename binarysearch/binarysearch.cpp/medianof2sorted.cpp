//this is with normal sol, not with O(logN)
#include<iostream>

void mergearrays(int arr1[], int arr2[],int n,int m,int result[]){
  int i=0;
  int j=0;
  int k=0;
while(i<n && j<m){
    if(arr1[i]<arr2[j]){
        result[k]=arr1[i];
        i++;
    }
    else{
        result[k]=arr2[j];
        j++;
    }
    k++;
}
    while(i < n){
        result[k] = arr1[i];
        i++;
        k++;
    }
       while(j < m){
        result[k] = arr2[j];
        j++;
        k++;
    }
}
double median( int arr[], int n){
    if(n%2!=0){
    return arr[n/2];
    }
    else{
        return (arr[n/2]+arr[(n/2)-1])/2.0;
    }
}