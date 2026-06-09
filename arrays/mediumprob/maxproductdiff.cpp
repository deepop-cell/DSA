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
int largest(int arr[], int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int min(int arr[], int n){
    int smallest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    return smallest;
}
int secondsmallest(int arr[], int n){
    int min1=arr[0];
    int min2=INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<min1){
        min2=min1;
        min1=arr[i];
        }
        else if(arr[i]>min1 && arr[i]<min2){
            min2=arr[i];
        }
    }
    return min2;
}
int ans(int arr[],int n){
    int a=largest(arr,n);
    int b=secondlargest(arr,n);
    int c=min(arr,n);
    int d=secondsmallest(arr,n);
    return (a*b)-(c*d);
}