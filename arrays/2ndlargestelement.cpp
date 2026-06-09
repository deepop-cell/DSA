#include<iostream>
#include<climits>
int secondlargest(int arr[], int n){
    int max1=arr[0];
    int max2=INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>max1){
        max2=max1;
        max1=arr[i];
        }
        else if(arr[i]<max1 && arr[i]>max2){
            max2=arr[i];
        }
    }
    return max2;
}