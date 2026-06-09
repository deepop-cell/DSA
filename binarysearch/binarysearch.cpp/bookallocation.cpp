#include<iostream>
int sum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int max(int arr[], int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
bool check(int arr[], int n , int k, int h){
    int i=0;
    int sum=0;
    int partition=1;
    while(1==1){
        if(i==n){
            break;
        }
        if(sum+arr[i]>h){
            partition++;
            sum=arr[i];
        }
        else{
            sum+=arr[i];
        }
        i++;
    }
    return partition<=k;

}
int res(int arr[], int n, int k){
    if(k>n){
        return -1;
    }
    int ans=-1;
    int low=max(arr,n);
    int high=sum(arr,n);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(arr,n,k,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}





