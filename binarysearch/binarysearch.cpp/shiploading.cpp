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
int sum(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
bool check(int arr[], int n, int days, int val){
int count=0;
int sum=0;
int i=0;
for(i=0;i<n;i++){
    sum+=arr[i];
    if(sum>val){
        count++;
        sum=arr[i];
    }
}
 return (count+1)<=days;
}
int min_cap(int arr[], int n, int days){
    int ans=-1;
    int low=max(arr,n);
    int high=sum(arr,n);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(arr,n,days,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;

}