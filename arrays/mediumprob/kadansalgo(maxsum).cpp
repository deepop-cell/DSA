#include<iostream>
int maxsumsubarray(int arr[], int n){
    int sum=arr[0];
    int bestsum=arr[0];
    for(int i=1;i<n;i++){
    if(sum<0){
           sum=arr[i];
    }
    else{
        sum+=arr[i];}
        if(sum>bestsum){
            bestsum=sum;
        }
    }
    return bestsum;
}