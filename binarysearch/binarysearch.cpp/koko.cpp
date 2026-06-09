#include<iostream>
int max(int arr[],int n){
    int maximum=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>maximum){
            maximum=arr[i];
        }
    }
    return maximum;
}
int min(int arr[], int n){
    int minimum=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<minimum){
            minimum=arr[i];
        }
    }
    return minimum;
}
bool caneat(int arr[], int n,int h, int speed){
    int time=0;
    for(int i=0;i<n;i++){
        time+=(arr[i]+speed-1)/speed;
    }
    if(time<=h){
        return true;
    }
    else{
        return false;
    }
}
int bananaeatingspeed(int arr[],int n,int h){
    int k=-1;
    int low=1;
    int high=max(arr,n);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(caneat(arr,n,h,mid)){
            high=mid-1;
            k=mid;
        }
        else{
            low=mid+1;
        }

    }
    return k;
}