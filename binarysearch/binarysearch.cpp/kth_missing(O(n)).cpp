#include<iostream>
int missing(int arr[], int n, int k){
    int low=0;
    int ans=-1;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }

    }
    return low+k;

}