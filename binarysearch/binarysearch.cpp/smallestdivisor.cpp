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
bool check(int arr[], int n,int threshhold,int div){
    int sum=0;
   for(int i=0;i<n;i++){
    sum+=(arr[i]+div-1)/div;//this is ceil fn.

   }
    return sum<=threshhold;
}
int divisor(int arr[], int n,int threshhold){
    int ans=-1;
    int low=1;
    int high=max(arr,n);
    while(low<=high){
        int mid=low+(high-low)/2;
        if(check(arr,n,threshhold,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return ans;

}