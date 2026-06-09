#include<iostream>
int zerofilledsubarrays(int arr[], int n){
    int count=0;
    int total=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count++;
        }
        else{
            total+=((count)*(count+1))/2.0;
            count=0;
        }
    }
    total += (count * (count + 1)) / 2;
    return total;
}